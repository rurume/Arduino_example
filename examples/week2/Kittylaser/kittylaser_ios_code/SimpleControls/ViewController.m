//
//  TableViewController.m
//  SimpleControl
//
//  Created by Cheong on 7/11/12.
//  Copyright (c) 2012 RedBearLab. All rights reserved.
//

#import "ViewController.h"
//#import "TouchView.h"
@interface ViewController ()

@end

@implementation ViewController

@synthesize ble;

//- (id)initWithStyle:(UITableViewStyle)style
//{
//    self = [super initWithStyle:style];
//    if (self) {
//        // Custom initialization
//    }
//    return self;
//}

- (void)viewDidLoad
{
    
    [super viewDidLoad];

    ble = [[BLE alloc] init];
    [ble controlSetup];
    ble.delegate = self;
    self.view.backgroundColor=[UIColor blackColor];
//     TOUCH=[[TouchView alloc]initWithFrame:CGRectMake(10,200,300,300)];
//    TOUCH.backgroundColor=[UIColor blueColor];
//    [self.view addSubview:TOUCH];
//    
//    
//    
//    CGRect buttonFrame = CGRectMake( 10, 40, 100, 30 );
//   button = [[UIButton alloc] initWithFrame: buttonFrame];
//    [button setTitle:@"button" forState:UIControlStateNormal];
//    [button setBackgroundColor:[UIColor whiteColor]];
//    [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
//    
//    [self.view addSubview:button];
//    [button addTarget:self
//               action:@selector(handleButtonClicked:)
//     forControlEvents:UIControlEventTouchUpInside
//     ];
//    for(int i=0;i<=300000;i++)
//    {}
    sleep(3);
    
    
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{

    
    UITouch* touch=[touches anyObject];
    
    CGPoint point = [touch  locationInView:self.view];
    
//        point.x=180-(point.x/320*180); //180度
//        point.y=180-(  (point.y-100) /320*180  );
 mydraw=[[draw alloc]initWithFrame:CGRectMake(0,100,320,320)];
    mydraw->x=point.x;
    mydraw->y=point.y;
    
    if(point.y>=100&&point.y<=420)
    {
        
        
     point.x=180-(point.x/320*180); //180度
        
//        point.x=120-(point.x/320*120)+30;
//        point.y+=40;
       // point.y=90-(  (point.y-100) /320*90  );
         point.y=180-(  (point.y-100) /320*180  );
        [self.view addSubview:mydraw];
        NSLog(@"%f,%f",point.x,point.y);

        
        
        UInt8 buf[3] = {0x02, 0x00, 0x00};
        
        buf[1] =point.x;
        NSData *data = [[NSData alloc] initWithBytes:buf length:3];
        [ble write:data];
        
        
        UInt8 buf1[3] = {0x03, 0x00, 0x00};
       
        buf1[1] = point.y;
        data = [[NSData alloc] initWithBytes:buf1 length:3];
        [ble write:data];
        
        
     
    }
//    [mydraw removeFromSuperview];
   
    
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    
    UITouch* touch=[touches anyObject];
    
    CGPoint point = [touch  locationInView:self.view];
    [mydraw removeFromSuperview];
    
     mydraw=[[draw alloc]initWithFrame:CGRectMake(0,100,320,320)];
    mydraw->x=point.x;
    mydraw->y=point.y;
   
   [self.view addSubview:mydraw];

    if(point.y>=100&&point.y<=420)
    {
    UInt8 buf[3] = {0x02, 0x00, 0x00};
   point.x=180-(point.x/320*180); //180度
         //point.y=180-(  (point.y-100) /320*180  );
//        point.x=120-(point.x/320*120)+30;
        
//        point.y+=40;
      //  point.y=90-(  (point.y-100) /320*90  );
//        point.y=120-(  (point.y-100) /320*120  )+30;
       
 point.y=180-(  (point.y-100) /320*180  );
    
    buf[1] =point.x;
    
    //        buf[2] =point.x >> 8;
    //       NSLog(@"%d %d",buf[1],buf[2]);
    
    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
    [ble write:data];
    
    
    UInt8 buf1[3] = {0x03, 0x00, 0x00};

    buf1[1] = point.y;
    //    buf[2] = (int)sldServodown.value >> 8;
    
    //    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
    data = [[NSData alloc] initWithBytes:buf1 length:3];
    
    [ble write:data];
        
    }
   
    
//    for (UIView *view in [self.view subviews])
//    { if([view isKindOfClass:[draw class]])
//        [view removeFromSuperview];
//        
//    }

   
}

-(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
//    for (UIView *view in [self.view subviews])
//    {
////        NSLog(@"%@",view);
//        if([view isKindOfClass:[draw class]])
//        [view removeFromSuperview];
//        
//        
//    }
//     [mydraw removeFromSuperview];
    for (UIView *view in [self.view subviews])
    { if([view isKindOfClass:[draw class]])
        [view removeFromSuperview];
    }

 mydraw=[[draw alloc]initWithFrame:CGRectMake(0,100,320,320)];
    UITouch* touch=[touches anyObject];
    
    CGPoint point = [touch  locationInView:self.view];
   
//    point.x=120-(point.x/320*120)+30;
    point.x=180-(point.x/320*180); //180度
//    point.y+=40;
 //   point.y=90-(  (point.y-100) /320*90  );
     point.y=180-(  (point.y-100) /320*180  );
    [self.view addSubview:mydraw];
//   [mydraw removeFromSuperview];
}




- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - BLE delegate

NSTimer *rssiTimer;

- (void)bleDidDisconnect
{
    NSLog(@"->Disconnected");

    [btnConnect setTitle:@"Connect" forState:UIControlStateNormal];
    [indConnecting stopAnimating];
    
    lblAnalogIn.enabled = false;
    swDigitalOut.enabled = false;
    swDigitalIn.enabled = false;
    swAnalogIn.enabled = false;
    sldServup.enabled = false;
    sldServodown.enabled = false;
    
    
    [rssiTimer invalidate];
}

// When RSSI is changed, this will be called
-(void) bleDidUpdateRSSI:(NSNumber *) rssi
{
    lblRSSI.text = rssi.stringValue;
}

-(void) readRSSITimer:(NSTimer *)timer
{
    [ble readRSSI];
}

// When disconnected, this will be called
-(void) bleDidConnect
{
    NSLog(@"->Connected");

    [indConnecting stopAnimating];
    
    lblAnalogIn.enabled = true;
    swDigitalOut.enabled = true;
    swDigitalIn.enabled = true;
    swAnalogIn.enabled = true;
    sldServup.enabled = true;
    sldServodown.enabled = true;
    
    swDigitalOut.on = false;
    swDigitalIn.on = false;
    swAnalogIn.on = false;
    sldServup.value = 30;
    sldServodown.value = 60;
    
    // send reset
    UInt8 buf[] = {0x04, 0x00, 0x00};
    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
    [ble write:data];

    // Schedule to read RSSI every 1 sec.
    
}

// When data is comming, this will be called
-(void) bleDidReceiveData:(unsigned char *)data length:(int)length
{
    NSLog(@"Length: %d", length);

    // parse data, all commands are in 3-byte
    for (int i = 0; i < length; i+=3)
    {
        NSLog(@"0x%02X, 0x%02X, 0x%02X", data[i], data[i+1], data[i+2]);

        if (data[i] == 0x0A)
        {
            if (data[i+1] == 0x01)
                swDigitalIn.on = true;
            else
                swDigitalIn.on = false;
        }
        else if (data[i] == 0x0B)
        {
            UInt16 Value;
            
            Value = data[i+2] | data[i+1] << 8;
            lblAnalogIn.text = [NSString stringWithFormat:@"%d", Value];
        }        
    }
}

#pragma mark - Actions

// Connect button will call to this
- (IBAction)btnScanForPeripherals:(id)sender
{
    if (ble.activePeripheral)
        if(ble.activePeripheral.state == CBPeripheralStateConnected)
        {
            [[ble CM] cancelPeripheralConnection:[ble activePeripheral]];
            [btnConnect setTitle:@"Connect" forState:UIControlStateNormal];
            return;
        }
    
    if (ble.peripherals)
        ble.peripherals = nil;
    
    [btnConnect setEnabled:false];
    [ble findBLEPeripherals:2];
    
    [NSTimer scheduledTimerWithTimeInterval:(float)2.0 target:self selector:@selector(connectionTimer:) userInfo:nil repeats:NO];
    
    [indConnecting startAnimating];
}

-(void) connectionTimer:(NSTimer *)timer
{
    [btnConnect setEnabled:true];
    [btnConnect setTitle:@"Disconnect" forState:UIControlStateNormal];
    
    if (ble.peripherals.count > 0)
    {
        [ble connectPeripheral:[ble.peripherals objectAtIndex:0]];
    }
    else
    {
        [btnConnect setTitle:@"Connect" forState:UIControlStateNormal];
        [indConnecting stopAnimating];
    }
}

-(IBAction)sendDigitalOut:(id)sender
{
    UInt8 buf[3] = {0x01, 0x00, 0x00};
    
    if (swDigitalOut.on)
        buf[1] = 0x01;
    else
        buf[1] = 0x00;
    
    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
    [ble write:data];
}

/* Send command to Arduino to enable analog reading */
-(IBAction)sendAnalogIn:(id)sender
{
    UInt8 buf[3] = {0xA0, 0x00, 0x00};
    
    if (swAnalogIn.on)
        buf[1] = 0x01;
    else
        buf[1] = 0x00;
    
    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
    [ble write:data];
}

// PWM slide will call this to send its value to Arduino
-(IBAction)sendPWM:(id)sender
//-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event

{
//
//    UInt8 buf[3] = {0x02, 0x00, 0x00};
//    
//    buf[1] = TOUCH->touchx;
//    buf[2] = (int)TOUCH->touchx >> 8;
//    NSLog(@"%d %d",buf[1],buf[2]);
//    
//    NSData *data = [[NSData alloc] initWithBytes:buf length:3];
//    [ble write:data];
}

// Servo slider will call this to send its value to Arduino
-(IBAction)sendServo:(id)sender
{
    
}



@end
