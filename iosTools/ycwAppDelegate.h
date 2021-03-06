//
//  ycwAppDelegate.h
//  iosTools
//
//  Created by YangCW on 16-6-2.
//  Copyright (c) 2016年 ycw. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "MyDeviceDeleget.h"
#include "deviceservice.h"
#include "filemanager.h"

typedef enum
{
    BU_Successful,                                        //Successful
    BU_NoBackupapp,                                       //AppleMobileBackup.app  not exist
    BU_NoSavebackuppath,                                  //The Save path not exist
    BU_UnknownError,                                      //Unknown error
    BU_InsufficientSpace,                                 //InsufficientSpace
    BU_ConnectFailed,                                     //Connecting to device failed
    BU_DeviceLost,                                         //Device Lost
    BU_PassWord,                                             //设备有锁屏
    BU_ITunesSetPassword,
    BU_STOPBACKUP,
    BU_NEEDCLOSEFINDMYIPHONE
}BackupError;

@interface ycwAppDelegate : NSObject <NSApplicationDelegate>{
    MyDeviceDeleget* deviceDeleget_;
    IBOutlet NSTextField *_lblDeviceName;
    IBOutlet NSTextField *_lbliOSVersion;
    IBOutlet NSTextField *_lblDeviceUDID;
    IBOutlet NSTextField *_lblAppPath;

    mg_ios::IOSDevice* currentDevice;
    NSTask    *backupTask_;
    int    taskState;
    NSString *_Uiid;
    mg_ios::DeviceService*  fileSerice_;
    mg_ios::FileManager*    fileManager_;
    struct afc_connection *_opencc;
}

@property (assign) IBOutlet NSWindow *window;
- (IBAction)clickListApps:(id)sender;
- (IBAction)clickBackup:(id)sender;
- (IBAction)clickCopyFile:(id)sender;
- (IBAction)clickClearFile:(id)sender;
- (IBAction)clickInstallApp:(id)sender;
- (IBAction)clickCrashReport:(id)sender;

@end
