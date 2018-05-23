//
//  EncryptionMD5.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EncryptionMD5 : NSObject

+ (NSString *)md5Encryption32:(NSString *)str;

+ (NSString *)md5Encryption16:(NSString *)str;

@end
