// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import <Foundation/Foundation.h>

@interface DBPeerRecord : NSObject
- (nonnull instancetype)initWithId:(int64_t)id
                                ip:(nonnull NSString *)ip
                          hostname:(nonnull NSString *)hostname
                       startHeight:(int32_t)startHeight
                      syncedHeight:(int32_t)syncedHeight
                      commonHeight:(int32_t)commonHeight
                           latency:(int32_t)latency
                         userAgent:(nonnull NSString *)userAgent
                          protocol:(int64_t)protocol;
+ (nonnull instancetype)peerRecordWithId:(int64_t)id
                                      ip:(nonnull NSString *)ip
                                hostname:(nonnull NSString *)hostname
                             startHeight:(int32_t)startHeight
                            syncedHeight:(int32_t)syncedHeight
                            commonHeight:(int32_t)commonHeight
                                 latency:(int32_t)latency
                               userAgent:(nonnull NSString *)userAgent
                                protocol:(int64_t)protocol;

@property (nonatomic, readonly) int64_t id;

@property (nonatomic, readonly, nonnull) NSString * ip;

@property (nonatomic, readonly, nonnull) NSString * hostname;

@property (nonatomic, readonly) int32_t startHeight;

@property (nonatomic, readonly) int32_t syncedHeight;

@property (nonatomic, readonly) int32_t commonHeight;

@property (nonatomic, readonly) int32_t latency;

@property (nonatomic, readonly, nonnull) NSString * userAgent;

@property (nonatomic, readonly) int64_t protocol;

@end
