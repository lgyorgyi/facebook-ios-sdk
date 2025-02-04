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

#import <UIKit/UIKit.h>

#if SWIFT_PACKAGE
 #import "FBSDKCoreKit.h"
#else
 #import <FBSDKCoreKit/FBSDKCoreKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@class FBSDKDeviceLoginViewController;

/*!
 @abstract A delegate for `FBSDKDeviceLoginViewController`
 */
NS_SWIFT_NAME(DeviceLoginViewControllerDelegate)
@protocol FBSDKDeviceLoginViewControllerDelegate <NSObject>

/*!
 @abstract Indicates the login was cancelled or timed out.
 */
- (void)deviceLoginViewControllerDidCancel:(FBSDKDeviceLoginViewController *)viewController;

/*!
 @abstract Indicates the login finished. The `FBSDKAccessToken.currentAccessToken` will be set.
 */
- (void)deviceLoginViewControllerDidFinish:(FBSDKDeviceLoginViewController *)viewController;

/*!
 @abstract Indicates an error with the login.
*/
- (void)deviceLoginViewController:(FBSDKDeviceLoginViewController *)viewController didFailWithError:(NSError *)error;

@end

/*!
 @abstract Use this view controller to initiate a Facebook Device Login.
 @discussion The `FBSDKDeviceLoginViewController` will dismiss itself and notify its delegate
  of the results. You should not re-use a `FBSDKDeviceLoginViewController` instance again.

  Upon success, `FBSDKAccessToken.currentAccessToken` will be set.

  See [Facebook Device Login]( https://developers.facebook.com/docs/facebook-login/for-devices ).

 @code
 // from your view controller:
 FBSDKDeviceLoginViewController *vc = [FBSDKDeviceLoginViewController new];
 vc.delegate = self;
 [self presentViewController:vc
                    animated:YES
                  completion:NULL];
 */
NS_SWIFT_NAME(FBDeviceLoginViewController)
@interface FBSDKDeviceLoginViewController : FBSDKDeviceViewControllerBase

/*!
 @abstract The delegate.
 */
@property (nullable, nonatomic, weak) id<FBSDKDeviceLoginViewControllerDelegate> delegate;

/*!
 @abstract The permissions to request.
 @discussion To provide the best experience, you should minimize the number of permissions you request, and only ask for them when needed.
 For example, do not ask for "user_location" until you the information is actually used by the app.

 Note this is converted to NSSet and is only
 an NSArray for the convenience of literal syntax.

 See [the permissions guide]( https://developers.facebook.com/docs/facebook-login/permissions/ ) for more details.
 */
@property (nonatomic, copy) NSArray<NSString *> *permissions;

/*!
 @abstract the optional URL to redirect the user to after they complete the login.
 @discussion the URL must be configured in your App Settings -> Advanced -> OAuth Redirect URIs
 */
@property (nullable, nonatomic, copy) NSURL *redirectURL;

@end

NS_ASSUME_NONNULL_END
