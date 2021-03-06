/**
 * Copyright 2009 Jeff Verkoeyen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <UIKit/UIKit.h>

@protocol CancelDelegate, HelpDelegate;

@interface OverlayView : UIView {
	UIImageView *imageView;
	NSMutableArray *_points;
	UIButton *cancelButton;
	UIButton *flashButton;
	UIButton *helpButton;
    UILabel *instructionsLabel;
	id<CancelDelegate, HelpDelegate> delegate;
	BOOL oneDMode;
    CGRect cropRect;
    NSString *displayedMessage;
    BOOL rectangleEnabled;
}

@property (nonatomic, retain) NSMutableArray*  points;
@property (nonatomic, assign) id<CancelDelegate, HelpDelegate> delegate;
@property (nonatomic, assign) BOOL oneDMode;
@property (nonatomic, assign) CGRect cropRect;
@property (nonatomic, copy) NSString *displayedMessage;

- (id)initWithFrame:(CGRect)theFrame
      cancelEnabled:(BOOL)isCancelEnabled
       flashEnabled:(BOOL)isFlashEnabled
        helpEnabled:(BOOL)isHelpEnabled
   rectangleEnabled:(BOOL)isRectangleEnabled
           oneDMode:(BOOL)isOneDModeEnabled
        withOverlay:(UIView*)overlay;

- (void)setPoint:(CGPoint)point;
- (void)setTorch:(BOOL)status;
- (BOOL)torchIsOn;

@end

@protocol CancelDelegate
- (void)cancelled;
@end

@protocol HelpDelegate
- (void)showHelp;
@end