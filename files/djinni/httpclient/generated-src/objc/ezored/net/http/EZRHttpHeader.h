// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>

@interface EZRHttpHeader : NSObject
- (nonnull instancetype)initWithName:(nonnull NSString *)name
                               value:(nonnull NSString *)value;
+ (nonnull instancetype)httpHeaderWithName:(nonnull NSString *)name
                                     value:(nonnull NSString *)value;

@property (nonatomic, readonly, nonnull) NSString * name;

@property (nonatomic, readonly, nonnull) NSString * value;

@end
