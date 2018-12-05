//
//  EncryptionRSA.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/12/5.
//  Copyright © 2018 Jiankun Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EncryptionRSA : NSObject

// return base64 encoded string
+ (NSString *)jk_encryptString:(NSString *)str publicKey:(NSString *)pubKey;
// return raw data
+ (NSData *)jk_encryptData:(NSData *)data publicKey:(NSString *)pubKey;
// return base64 encoded string
+ (NSString *)jk_encryptString:(NSString *)str privateKey:(NSString *)privKey;
// return raw data
+ (NSData *)jk_encryptData:(NSData *)data privateKey:(NSString *)privKey;

// decrypt base64 encoded string, convert result to string(not base64 encoded)
+ (NSString *)jk_decryptString:(NSString *)str publicKey:(NSString *)pubKey;
+ (NSData *)jk_decryptData:(NSData *)data publicKey:(NSString *)pubKey;
+ (NSString *)jk_decryptString:(NSString *)str privateKey:(NSString *)privKey;
+ (NSData *)jk_decryptData:(NSData *)data privateKey:(NSString *)privKey;

@end

NS_ASSUME_NONNULL_END
