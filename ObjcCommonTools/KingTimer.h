//
//  KingTimer.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/25.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^TimeoutBlock)(void);
typedef void(^TimecontinueBlock)(NSString *timeString);

@interface KingTimer : NSObject

/**
 倒计时方法

 @param time 倒计时时间
 @param outBlock 结束后的回调
 @param continueBlock 每一秒的回调
 */
+ (void)countdownTimer:(NSInteger)time timeout:(TimeoutBlock)outBlock timecontinue:(TimecontinueBlock)continueBlock;

+ (void)delayTimeAfterExe:(NSInteger)time timeout:(TimeoutBlock)outBlock;

@end
