/**
 * Copyright (c) 2013 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * This generated code and related technologies are covered by patents
 * or patents pending by Appcelerator, Inc.
 */

#include "hyperloop_Logger.h"
#include <ppltasks.h>

using namespace concurrency;

static Windows::Storage::StorageFile^ logFile = nullptr;
static bool logFileGenerating = false;
static Platform::Array<Platform::String^>^ logQueue = ref new Platform::Array<Platform::String^>(100);
static int logIndex = 0;

void Logger::log(Platform::String^ string) {
    string += "\r\n";
    OutputDebugStringW(std::wstring(string->Data()).c_str());
/*
    if (logFileGenerating) {
        OutputDebugStringW(L"Queued...\r\n");
        logQueue[logIndex++] = string;
    }
    else if (logFile == nullptr) {
        logFileGenerating = true;
	OutputDebugStringW(L"Queued...\r\n");
        logQueue[logIndex++] = string;
	OutputDebugStringW(L"Creating log file...\r\n");
        auto logFolder = Windows::Storage::ApplicationData::Current->LocalFolder;
        auto task = create_task(logFolder->CreateFileAsync("log.txt", Windows::Storage::CreationCollisionOption::ReplaceExisting));
        task.then([](Windows::Storage::StorageFile ^file) {
		OutputDebugStringW(std::wstring(("Created log file at " + file->Path + "\r\n")->Data()).c_str());
                logFile = file;
                if (logIndex > 0) {
                    auto output = logQueue[0];
                    for (int i = 1; i < logIndex; i++) {
                        output += logQueue[i];
                    }
                    Windows::Storage::FileIO::AppendTextAsync(logFile, output);
                }
                logIndex = 0;
                logQueue = nullptr;
                logFileGenerating = false;
            });
    }
    else {
        Windows::Storage::FileIO::AppendTextAsync(logFile, string);
    }
*/
}
