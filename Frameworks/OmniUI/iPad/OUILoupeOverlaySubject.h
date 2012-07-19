// Copyright 2010 The Omni Group.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

@protocol OUILoupeOverlaySubject <NSObject>
@optional

// These will only be sent to non-opaque subject views. If -drawLoupeOverlayBackgroundInRect: it will be used in preference to -loupeOverlayBackgroundColor. If neither is implemented, white will be used.

- (void)drawLoupeOverlayBackgroundInRect:(CGRect)rect; // In the subject view's coordinate system
- (UIColor *)loupeOverlayBackgroundColor;

@required
// These methods are confusingly named; -transformToRenderingSpace actually returns a transform that will take you *from* rendering space to UIKit's  view coordinate system, but that's the transform you want to concat with the CTM in order to "be in" rendering space when you draw (that is, to "go to rendering space"). Likewise -transformFromRenderingSpace returns a transform that will convert a point's coordinates in UIKit's space *to* the same point's coordinates in rendering space.
- (CGAffineTransform)transformToRenderingSpace;
- (CGRect)convertRectToRenderingSpace:(CGRect)rect;

// Draw w/in a scaled (and possibly flipped) coordinate system.
- (void)drawScaledContent:(CGRect)rect;

@end
