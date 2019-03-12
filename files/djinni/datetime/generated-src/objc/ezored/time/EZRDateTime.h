// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import <Foundation/Foundation.h>


@interface EZRDateTime : NSObject

+ (nonnull NSDate *)getDateTimeFromString:(nonnull NSString *)value;

+ (nonnull NSString *)getStringFromDateTime:(nonnull NSDate *)value;

+ (nonnull NSString *)getCurrentDateTimeAsString;

+ (nonnull NSDate *)getCurrentDateTime;

+ (nonnull NSDate *)getDateTimeFromSeconds:(int64_t)value;

+ (nonnull NSDate *)getDateTimeFromMilliseconds:(int64_t)value;

+ (int64_t)getTimestampInMillisecondsFromDateTime:(nonnull NSDate *)value;

+ (int64_t)getTimestampInSecondsFromDateTime:(nonnull NSDate *)value;

@end
