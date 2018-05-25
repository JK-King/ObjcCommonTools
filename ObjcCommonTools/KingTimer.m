//
//  KingTimer.m
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/25.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import "KingTimer.h"

@implementation KingTimer

+ (void)countdownTimer:(NSInteger)time timeout:(TimeoutBlock)outBlock timecontinue:(TimecontinueBlock)continueBlock {
    __block NSInteger timeout = time;  //设置倒计时
    // 1.定义全局队列
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    // 2.定义timer
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
    dispatch_source_set_timer(timer, DISPATCH_TIME_NOW, 1.0 * NSEC_PER_SEC, 0);
    dispatch_source_set_event_handler(timer, ^{
        if (timeout < 0) {
            dispatch_source_cancel(timer);
            dispatch_async(dispatch_get_main_queue(), ^{
                outBlock();
            });
        }else{
            NSString *strTime = [NSString stringWithFormat:@"%@", @(timeout)];
            dispatch_async(dispatch_get_main_queue(), ^{
                continueBlock(strTime);
            });
            timeout--;
        }
    });
    dispatch_resume(timer);
}

+ (void)delayTimeAfterExe:(NSInteger)time timeout:(TimeoutBlock)outBlock {
    //该方法的第一个参数是time，第二个参数是dispatch_queue，第三个参数是要执行的block。
    //在主线程中延迟执行  dispatch_after的真正含义是在time秒后把任务添加进队列中，并不是表示在time秒后执行
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        outBlock();
    });
}

@end
