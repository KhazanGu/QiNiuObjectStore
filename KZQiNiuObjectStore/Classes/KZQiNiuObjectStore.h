//
//  KZQiNiuObjectStore.h
//  KZQiNiuObjectStore
//
//  Created by Khazan on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KZQiNiuObjectStore : NSObject

# pragma mark - upload data

// kind == 0, upload file data via formdata - large memory use
// kind == 1, splite data and upload subdata - little memory use

- (void)uploadWithData:(NSData *)data
              fileName:(NSString *)fileName
                  host:(NSString *)host
                bucket:(NSString *)bucket
             accessKey:(NSString *)accessKey
             secretKey:(NSString *)secretKey
                  kind:(NSUInteger)kind
               success:(void (^)(void))success
               failure:(void (^)(void))failure;


# pragma mark - splite data and upload subdata one by one - very little memory use

- (void)uploadWithFilePath:(NSString *)filePath
                  fileName:(NSString *)fileName
                      host:(NSString *)host
                    bucket:(NSString *)bucket
                 accessKey:(NSString *)accessKey
                 secretKey:(NSString *)secretKey
                      kind:(NSUInteger)kind
                   success:(void (^)(void))success
                   failure:(void (^)(void))failure;

@end

NS_ASSUME_NONNULL_END
