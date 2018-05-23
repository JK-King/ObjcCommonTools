//
//  EncryptionDES.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EncryptionDES : NSObject

+ (NSString *)encryptUseDES:(NSString *)plainText withKey:(NSString *)key;

+ (NSString *)decryptUseDES:(NSString*)cipherText withKey:(NSString *)key;

@end
