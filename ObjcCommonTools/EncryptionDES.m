//
//  EncryptionDES.m
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import "EncryptionDES.h"
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>

@implementation EncryptionDES

/*字符串加密
 *参数
 *plainText : 加密明文
 *key       : 密钥 64位
 */
+ (NSString *)encryptUseDES:(NSString *)plainText withKey:(NSString *)key
{
    NSString *ciphertext = nil;
    const char *textBytes = [plainText UTF8String];
    NSUInteger dataLength = [plainText length];
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    Byte iv[] = {1,2,3,4,5,6,7,8};
    size_t numBytesEncrypted = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt, kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding|kCCOptionECBMode,
                                          [key UTF8String], kCCKeySizeDES,
                                          iv,
                                          textBytes, dataLength,
                                          buffer, 1024,
                                          &numBytesEncrypted);
    if (cryptStatus == kCCSuccess) {
        ciphertext = [EncryptionDES parseByteArray2HexString:buffer withLength:(NSUInteger)numBytesEncrypted];
    }
    return ciphertext;
}

+(NSString *)parseByteArray2HexString:(Byte[])bytes withLength:(NSUInteger)length
{
    NSMutableString *hexStr = [[NSMutableString alloc]init];
    int i = 0;
    if(bytes)
    {
        while (i < length)
        {
            NSString *hexByte = [NSString stringWithFormat:@"%X",bytes[i] & 0xff];///16进制数
            if([hexByte length] == 1) {
                [hexStr appendFormat:@"0%@", hexByte];
            }else {
                [hexStr appendFormat:@"%@", hexByte];
            }
            i++;
        }
    }
    return hexStr;
}

//解密
+ (NSString *)decryptUseDES:(NSString*)cipherText withKey:(NSString *)key
{
    NSData* cipherData = [EncryptionDES convertHexStrToData:cipherText];
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    size_t numBytesDecrypted = 0;
    Byte iv[] = {1,2,3,4,5,6,7,8};
    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
                                          kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding|kCCOptionECBMode,
                                          [key UTF8String],
                                          kCCKeySizeDES,
                                          iv,
                                          [cipherData bytes],
                                          [cipherData length],
                                          buffer,
                                          1024,
                                          &numBytesDecrypted);
    NSString* plainText = nil;
    if (cryptStatus == kCCSuccess) {
        NSData* data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesDecrypted];
        plainText = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    }
    return plainText;
}
//将16进制的字符串转换成NSData
+ (NSMutableData *)convertHexStrToData:(NSString *)str {
    if (!str || [str length] == 0) {
        return nil;
    }
    
    NSMutableData *hexData = [[NSMutableData alloc] initWithCapacity:8];
    NSRange range;
    if ([str length] %2 == 0) {
        range = NSMakeRange(0,2);
    } else {
        range = NSMakeRange(0,1);
    }
    for (NSInteger i = range.location; i < [str length]; i += 2) {
        unsigned int anInt;
        NSString *hexCharStr = [str substringWithRange:range];
        NSScanner *scanner = [[NSScanner alloc] initWithString:hexCharStr];
        
        [scanner scanHexInt:&anInt];
        NSData *entity = [[NSData alloc] initWithBytes:&anInt length:1];
        [hexData appendData:entity];
        
        range.location += range.length;
        range.length = 2;
    }
    
    return hexData;
}

@end
