// Copyright (c) 2014-present, Facebook, Inc. All rights reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "TargetConditionals.h"

#if !TARGET_OS_TV

#import <Foundation/Foundation.h>
#import "FBSDKDialogProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A model for an instant games switchAsync cross play request.
 */
NS_SWIFT_NAME(SwitchContextContent)
@interface FBSDKSwitchContextContent : NSObject <NSSecureCoding,FBSDKValidatable>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
  Builds a content object that will be use to display a switch context dialog
 @param contextID  The context ID of the context instance to switch and set as the current game context
 */
- (instancetype)initDialogContentWithContextID:(NSString*)contextID
NS_SWIFT_NAME(init(contextID:));

/**
 The context token of the existing context for which this request is being made.
 @return The context token of the existing context
 */
@property (nonatomic, copy) NSString *contextTokenID;
@end

NS_ASSUME_NONNULL_END

#endif
