//
//  draw.m
//  ArduinoLaser
//
//  Created by amber on 2014/7/17.
//  Copyright (c) 2014年 RedBearLab. All rights reserved.
//

#import "draw.h"

@implementation draw

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor=[UIColor clearColor];
    }
    return self;
}


- (void)drawRect:(CGRect)rect
{
    [self drawCirce];
}

-(void)drawCirce{
    UIBezierPath* path=[UIBezierPath bezierPath];
    [[UIColor redColor]setFill ];
    NSLog(@"x=%d y=%d",x,y);
    [path addArcWithCenter:CGPointMake(x, y-140) radius:10 startAngle:0 endAngle:2*M_PI clockwise:NO];
    [path stroke];
    [path fill];
    
}
@end
