/*
 * UITextDragging.h
 *
 * UIKit (c) 2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIDragInteraction.h>
#import <UIKit/UITextInput.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, UITextDragOptions) {
    UITextDragOptionsNone = 0,
    
    /* By default, previews generated by the system will retain
     * the foreground and background text colors.
     * Activating this option causes those colors to be stripped away,
     * resulting in a text preview with black text on a clear background.
     * This affects only the preview, not the contents of the drag.
     * Any embedded images in the preview will remain as they are.
     */
    UITextDragOptionStripTextColorFromPreviews = (1 << 0)
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@protocol UITextDragDelegate;

/* Defines a text draggable control.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@protocol UITextDraggable <UITextInput>

@property (nonatomic, weak, nullable) id<UITextDragDelegate> textDragDelegate;

/* The text drag interaction that UIKit installs on the text control.
 * Use this to explicitly disable drag interactions on system text controls,
 * if desired.
 */
@property (nonatomic, readonly, nullable) UIDragInteraction *textDragInteraction;

/* Returns whether this control currently has at least one active drag session.
 */
@property (nonatomic, readonly, getter=isTextDragActive) BOOL textDragActive;

@property (nonatomic) UITextDragOptions textDragOptions;

@end


@class UIDragItem, UITargetedDragPreview;
@protocol UIDragSession, UITextDragRequest;

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@protocol UITextDragDelegate <NSObject>

@optional

/* Implement this to provide custom drag items when dragging out of a text control.
 * If you return an empty array here, no drag will occur.
 * The drag request provides the text range from which the user is dragging, and
 * a set of default drag items which would be used if this delegate method were
 * not implemented. You can modify and/or augment these at will.
 *
 * Note: this method might be called more than once. For instance, if the control
 * is asked to provide more items to add to an existing session.
 * You can detect this by checking the `existingItems` in the drag request.
 */
- (NSArray<UIDragItem *> *)textDraggableView:(UIView<UITextDraggable> *)textDraggableView itemsForDrag:(id<UITextDragRequest>)dragRequest;

/* Provide a preview for lifting the item out of the text control.
 * If you return nil, the drag interaction will provide a default preview.
 *
 * Note: This will not be called for items obtained from a UITextDragRequest’s suggestedItems
 * (via textDraggableView:itemsForDrag:).
 * The text control will use its own previews for those items.
 */
- (nullable UITargetedDragPreview *)textDraggableView:(UIView<UITextDraggable> *)textDraggableView dragPreviewForLiftingItem:(UIDragItem *)item session:(id<UIDragSession>)session;

/* Called when the lift animation is about to start.
 * Use the animator to animate your own changes alongside the system animation,
 * or to be called when the lift animation completes.
 */
- (void)textDraggableView:(UIView<UITextDraggable> *)textDraggableView willAnimateLiftWithAnimator:(id<UIDragAnimating>)animator session:(id<UIDragSession>)session;

/* Called when the user actually begins dragging.
 * At that point, the text has lifted out of the text control.
 * `textDraggableView:dragSessionDidEnd:withOperation:` will be called when the drag ends.
 */
- (void)textDraggableView:(UIView<UITextDraggable> *)textDraggableView dragSessionWillBegin:(id<UIDragSession>)session;

/* Called when a drag out of this text control has ended.
 * The operation tells you what happened on the drop side.
 */
- (void)textDraggableView:(UIView<UITextDraggable> *)textDraggableView dragSessionDidEnd:(id<UIDragSession>)session withOperation:(UIDropOperation)operation;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@protocol UITextDragRequest <NSObject>

@required

/* The text range being dragged.
 */
@property (nonatomic, readonly) UITextRange *dragRange;

/* The suggested items that the text control would return,
 * if the responsible delegate method were not implemented.
 * This is populated lazily, so only use it when you need it.
 */
@property (nonatomic, readonly) NSArray<UIDragItem *> *suggestedItems;

/* The existing items in the session.
 * Will be filled when we request new items.
 */
@property (nonatomic, readonly) NSArray<UIDragItem *> *existingItems;

/* Indicates whether the drag context contains a selection.
 * Use this to disable dragging from an attachment or links
 * without them being selected. (In those cases, `selected` will be false.)
 * For regular dragged text, this will always be true.
 */
@property (nonatomic, readonly, getter=isSelected) BOOL selected;

/* The current drag session.
 */
@property (nonatomic, readonly) id<UIDragSession> dragSession;

@end

NS_ASSUME_NONNULL_END

