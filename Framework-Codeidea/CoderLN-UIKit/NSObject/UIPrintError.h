/*
 * UIPrintError.h
 *
 * UIKit (c) 2010-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSErrorDomain const UIPrintErrorDomain __TVOS_PROHIBITED;

enum {
    UIPrintingNotAvailableError = 1,  // cannot print at this time
    UIPrintNoContentError,            // empty list of files or images
    UIPrintUnknownImageFormatError,   // unrecognized image format
    UIPrintJobFailedError,            // internal error with print job
} __TVOS_PROHIBITED;
NS_ASSUME_NONNULL_END

