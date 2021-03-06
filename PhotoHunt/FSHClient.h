/*
 *
 * Copyright 2013 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//  FSHClient.h
//  PhotoHunt

#import "AFHTTPClient.h"
#import <Foundation/Foundation.h>
#import "FSHAccessToken.h"
#import "FSHPhoto.h"

@interface FSHClient : AFHTTPClient

+ (FSHClient *)sharedClient;

- (NSString *)pathForPhoto:(NSInteger)photoId;

- (NSString *)pathForDisconnect;

- (NSString *)pathToDeletePhoto:(NSInteger)photoId;

- (NSString *)pathToPutVote;

- (NSDictionary *)paramsToVoteForPhoto:(id)photoId;

- (NSString *)pathForUploadUrl;

- (NSString *)pathForFriends;

- (NSString *)pathForThemes;

- (NSString *)pathForPhotosByTheme:(NSInteger)themeId friendsOnly:(BOOL)friendsOnly;

- (NSString *)pathForConnect;

- (NSDictionary *)paramsForConnectWithToken:(FSHAccessToken *)token;

- (void)uploadPhoto:(UIImage *)image
            success:(void (^)(AFHTTPRequestOperation *operation, FSHPhoto *photo))success
            failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

@end