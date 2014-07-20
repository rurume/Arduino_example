//
//  TableViewController.h
//  SimpleControl
//
//  Created by Cheong on 7/11/12.
//  Copyright (c) 2012 RedBearLab. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BLE.h"

#import "draw.h"
@interface ViewController : UIViewController <BLEDelegate>
{
    IBOutlet UIButton *btnConnect;
   IBOutlet UISwitch *swDigitalIn;
    IBOutlet UISwitch *swDigitalOut;
    IBOutlet UISwitch *swAnalogIn;
    IBOutlet UILabel *lblAnalogIn;
    IBOutlet UISlider *sldServup;
    IBOutlet UISlider *sldServodown;
    IBOutlet UIActivityIndicatorView *indConnecting;
    IBOutlet UILabel *lblRSSI;
    UIButton *button;
    
    
    int touchx;
    int touchy;
    
    draw *mydraw;
}

@property (strong, nonatomic) BLE *ble;

@end
