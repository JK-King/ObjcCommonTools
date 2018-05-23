//
//  CommonHeader.h
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#ifndef CommonHeader_h
#define CommonHeader_h

#ifdef DEBUG
#define DBLog(fmt, ...) NSLog((@"function:%s-[line:%d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DBLog(...);
#endif

#endif /* CommonHeader_h */
