/*
 * UIPasteConfigurationSupporting.h
 *
 * UIKit (c) 2007-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPasteConfiguration;

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UIPasteConfigurationSupporting <NSObject>

@property (nonatomic, copy, nullable) UIPasteConfiguration *pasteConfiguration;

@optional
- (void)pasteItemProviders:(NSArray<NSItemProvider *> *)itemProviders;
- (BOOL)canPasteItemProviders:(NSArray<NSItemProvider *> *)itemProviders;

@end
NS_ASSUME_NONNULL_END

