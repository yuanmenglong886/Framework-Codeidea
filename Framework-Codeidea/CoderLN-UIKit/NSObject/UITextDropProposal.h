/*
 * UITextDropProposal.h
 *
 * UIKit (c) 2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDropInteraction.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, UITextDropAction) {
    /* Inserts the text at the provided location. Other text is not affected.
     */
    UITextDropActionInsert = 0,
    
    /* If the target has a selection, replaces the selection with the dropped text.
     * Otherwise, this behaves the same as UITextDropInsert.
     */
    UITextDropActionReplaceSelection,
    
    /* Replaces all the text in the target with the dropped text,
     * via `setAttributedText:`.
     */
    UITextDropActionReplaceAll,
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

typedef NS_ENUM(NSUInteger, UITextDropProgressMode) {
    /* Uses the default system UI for progress.
     * This blocks input to the application while the drop is happening.
     */
    UITextDropProgressModeSystem = 0,
    
    /* No progress UI is shown. You're on your own.
     */
    UITextDropProgressModeCustom
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

typedef NS_ENUM(NSUInteger, UITextDropPerformer) {
    /* The text droppable view will handle the drop.
     * This is the default behavior.
     *
     * Note: `-textDroppableView:willPerformDrop:` will be called, if it is implemented,
     * but it is not required.
     */
    UITextDropPerformerView = 0,
    
    /* The delegate will be responsible for performing the drop, and
     * the default data loading provided by the text droppable view
     * will not be invoked.
     *
     * The delegate must implement `-textDroppableView:willPerformDrop:`,
     * with custom code to start loading data. If it does not, then the text
     * droppable view will handle the drop, as if `UITextDropPerformerView`
     * was specified.
     */
    UITextDropPerformerDelegate,
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);


UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@interface UITextDropProposal : UIDropProposal <NSCopying>

/* Note: creating a UITextDropProposal sets the superclass's .precise property to true.
 */

/* The proposed text drop action. The default value is UITextDropInsert.
 */
@property (nonatomic) UITextDropAction dropAction;

/* The progress mode to be used. The default value is UITextDropProgressModeSystem.
 */
@property (nonatomic) UITextDropProgressMode dropProgressMode;

/* Specifies whether the drop is allowed to use "fast" inline operations
 * for drags between the same view. This will not use the data in the
 * items, but instead moves or copies text from the original positions
 * to the dropped position.
 * Defaults to YES.
 */
@property (nonatomic) BOOL useFastSameViewOperations;

/* Defines who will be responsible for performing the drop.
 * The performer must:
 * - load the data from the item providers
 * - insert it into the text droppable view
 * - provide a preview for the drop
 *
 * The default is `UITextDropPerformerView`.
 */
@property (nonatomic) UITextDropPerformer dropPerformer;

@end
NS_ASSUME_NONNULL_END

