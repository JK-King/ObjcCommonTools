//
//  VerificationTools.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VerificationTools : NSObject

/**
 校验手机号格式
 
 @param mobile 手机号
 @return 布尔值
 */
+ (BOOL)valiMobile:(NSString *)mobile;

/**
 校验密码组合
 
 1、不能全部为数字
 2、不能全部为字母
 3、必须包含字母和数字
 4、8-20位
 
 @param password 密码
 @return 是否符合组合
 */
+ (BOOL)checkPassword:(NSString *)password;

/**
 校验验证码
 
 @param number 验证码
 @return 是否符合
 */
+ (BOOL)checkCodeNumber:(NSString *)number;

/**
 检验字符串是否含有中文
 
 @param stringChecked 字符串
 @return 是否含有
 */
+ (BOOL)checkStringContainChinese:(NSString *)stringChecked;

/**
 检验身份证号是否合法
 
 @param identity 字符串
 @return 是否含有
 */
+ (BOOL)checkIdentityValid:(NSString *)identity;

/**
 校验邮箱的合法性

 @param email 邮箱账号
 @return 是否符合
 */
+ (BOOL)checkEmailAdress:(NSString *)email;

/**
 校验银行账号的合法性

 @param cardNumber 银行卡号
 @return 是否合法
 */
+ (BOOL)checkBankCard:(NSString *)cardNumber;


/**
 校验是否为中文

 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiChineseCharacters:(NSString*)string;

/**
 校验是否为数字

 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiNumber:(NSString*)string;

/**
 校验是否为小写字符
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiLowercaseLetter:(NSString*)string;

/**
 校验是否为大写字符
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiACapital:(NSString*)string;

/**
 校验是否为大小写字符
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiCapitalAndLowercaseLetter:(NSString*)string;

/**
 校验是否为大小写字符或者数字
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiLettersOrNumbers:(NSString*)string;

/**
 校验是否为大小写字符或者数字 限制长度
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiNumberOrLetters:(NSString*)string;

/**
 校验是否为汉字或者数字
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiChineseOrNumbers:(NSString*)string;

/**
 校验是否为汉字或者数字 限制长度
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiChineseOrNumbersLimit:(NSString*)string;

/**
 校验是否为汉字、大小写或数字
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiChineseOrLettersAndNumbers:(NSString*)string;

/**
 校验是否为汉字、大小写、数字或_ 限制长度
 
 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiChineseOrLettersNumberslimit:(NSString*)string;

/**
 校验是否为1开头的数字并且长度为11

 @param string 字符串
 @return 是否合法
 */
+ (BOOL)valiFirstNumberAddLength:(NSString *)string;

@end
