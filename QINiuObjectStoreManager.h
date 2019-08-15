//
//  QINiuObjectStoreManager.h
//  CocoaAsyncSocket
//
//  Created by Khazan on 2019/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QINiuObjectStoreManager : NSObject

+ (void)uploadFileWithData:(NSData *)data
                      host:(NSString *)host
                    bucket:(NSString *)bucket
                  fileName:(NSString *)fileName
                 accessKey:(NSString *)accessKey
                 secretKey:(NSString *)secretKey
                   success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
                   failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
