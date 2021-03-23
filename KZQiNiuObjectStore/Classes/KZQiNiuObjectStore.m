//
//  KZQiNiuObjectStore.m
//  KZQiNiuObjectStore
//
//  Created by Khazan on 2021/3/15.
//

#import "KZQiNiuObjectStore.h"
#import "KZUploadViaFormData.h"
#import "KZUploadViaDataSplit.h"

@interface KZQiNiuObjectStore ()

@property (nonatomic, strong) KZUploadViaDataSplit *uploader;

@end

@implementation KZQiNiuObjectStore

- (void)uploadDataViaFormDataWithData:(NSData *)data
                             fileName:(NSString *)fileName
                                 host:(NSString *)host
                               bucket:(NSString *)bucket
                            accessKey:(NSString *)accessKey
                            secretKey:(NSString *)secretKey
                              success:(void (^)(void))success
                              failure:(void (^)(void))failure {
    
    [[[KZUploadViaFormData alloc] init] uploadWithData:data
                                              fileName:fileName
                                                  host:host
                                                bucket:bucket
                                             accessKey:accessKey
                                             secretKey:secretKey
                                               success:success
                                               failure:failure];
}


- (void)uploadDataViaPartlyWithData:(NSData *)data
                           fileName:(NSString *)fileName
                               host:(NSString *)host
                             bucket:(NSString *)bucket
                          accessKey:(NSString *)accessKey
                          secretKey:(NSString *)secretKey
                            success:(void (^)(void))success
                            failure:(void (^)(void))failure {
    
    NSUInteger chunkSize = 1024 * 1024;
    
    [self.uploader splitDataAndUploadWithData:data
                                    chunkSize:chunkSize
                                     fileName:fileName
                                         host:host
                                       bucket:bucket
                                    accessKey:accessKey
                                    secretKey:secretKey
                                      success:success
                                      failure:failure];
}


- (void)uploadFileWithPath:(NSString *)filePath
                  fileName:(NSString *)fileName
                      host:(NSString *)host
                    bucket:(NSString *)bucket
                 accessKey:(NSString *)accessKey
                 secretKey:(NSString *)secretKey
                   success:(void (^)(void))success
                   failure:(void (^)(void))failure {
    
    NSUInteger chunkSize = 1024 * 1024;
    
    [self.uploader readAndUploadFileInPartialWithFilePath:filePath
                                                chunkSize:chunkSize
                                                 fileName:fileName
                                                     host:host
                                                   bucket:bucket
                                                accessKey:accessKey
                                                secretKey:secretKey
                                                  success:success
                                                  failure:failure];
}


+ (KZQiNiuObjectStore *)sharedInstance {
    static KZQiNiuObjectStore *store = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        store = [[KZQiNiuObjectStore alloc] init];
        store.uploader = [[KZUploadViaDataSplit alloc] init];
    });
    return store;
}

@end
