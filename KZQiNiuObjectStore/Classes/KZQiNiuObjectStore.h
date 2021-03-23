//
//  KZQiNiuObjectStore.h
//  KZQiNiuObjectStore
//
//  Created by Khazan on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KZQiNiuObjectStore : NSObject

# pragma mark - upload full data via formdata - large memory use

- (void)uploadDataViaFormDataWithData:(NSData *)data
                             fileName:(NSString *)fileName
                                 host:(NSString *)host
                               bucket:(NSString *)bucket
                            accessKey:(NSString *)accessKey
                            secretKey:(NSString *)secretKey
                              success:(void (^)(void))success
                              failure:(void (^)(void))failure;


# pragma mark - split data and upload at the same time - large memory use

- (void)uploadDataViaPartlyWithData:(NSData *)data
                           fileName:(NSString *)fileName
                               host:(NSString *)host
                             bucket:(NSString *)bucket
                          accessKey:(NSString *)accessKey
                          secretKey:(NSString *)secretKey
                            success:(void (^)(void))success
                            failure:(void (^)(void))failure;


# pragma mark - split file to data lump and upload one by one - very little memory use

- (void)uploadFileWithPath:(NSString *)filePath
                  fileName:(NSString *)fileName
                      host:(NSString *)host
                    bucket:(NSString *)bucket
                 accessKey:(NSString *)accessKey
                 secretKey:(NSString *)secretKey
                   success:(void (^)(void))success
                   failure:(void (^)(void))failure;


+ (KZQiNiuObjectStore *)sharedInstance;

@end

NS_ASSUME_NONNULL_END
