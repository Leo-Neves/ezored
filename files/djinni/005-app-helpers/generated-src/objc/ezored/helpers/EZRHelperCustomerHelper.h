// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

#import "ezored/domain/EZRDomainCustomer.h"
#import <Foundation/Foundation.h>


@interface EZRHelperCustomerHelper : NSObject

+ (BOOL)isLogged;

+ (nonnull NSString *)getToken;

+ (nonnull EZRDomainCustomer *)create;

+ (void)onCustomerLogin:(nonnull EZRDomainCustomer *)customer;

@end
