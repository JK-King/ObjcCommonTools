//
//  ViewController.m
//  Demo
//
//  Created by Jiankun Zhang on 2018/5/23.
//  Copyright © 2018年 Jiankun Zhang. All rights reserved.
//

#import "ViewController.h"
#import "VerificationTools.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSLog(@"%d", [VerificationTools checkEmailAdress:@"zhang_jiankun521@162.com"]);
    
    NSLog(@"%d", [VerificationTools checkBankCard:@"6250760009375240"]);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
