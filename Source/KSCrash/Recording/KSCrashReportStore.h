//
//  KSCrashReportStore.h
//
//  Created by Karl Stenerud on 2012-02-05.
//
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <sys/types.h>

#define KSCRS_MAX_PATH_LENGTH 500

/** Initialize the report store.
 *
 * @param appName The application's name.
 * @param reportsPath Full path to directory where the reports are to be stored (path will be created if needed).
 */
void kscrs_initialize(const char* appName, const char* reportsPath);

/** Get the path to the next crash report to be generated.
 * Max length for paths is KSCRS_MAX_PATH_LENGTH
 *
 * @param crashReportPathBuffer Buffer to store the crash report path.
 */
void kscrs_getCrashReportPath(char* crashReportPathBuffer);

/** Get the number of reports on disk.
 */
int kscrs_getReportCount();


/** Get a list of IDs for all reports on disk.
 *
 * @param reportIDs An array big enough to hold all report IDs.
 * @param count How many reports the array can hold.
 *
 * @return The number of report IDs that were placed in the array.
 */
int kscrs_getReportIDs(int64_t* reportIDs, int count);

/** Read a report.
 *
 * @param reportID The report's ID.
 * @param reportPtr (out) Will be filled with a pointer to the contents of the report, or NULL if not found.
 *                        Caller MUST call free() on the returned pointer if not NULL.
 * @param reportLengthPtr (out) Will be filled with the length of the report in bytes, or 0 if not found.
 */
void kscrs_readReport(int64_t reportID, char** reportPtr, int* reportLengthPtr);

/** Add a custom report to the store.
 *
 * @param report The report's contents (must be JSON encoded).
 * @param reportLength The length of the report in bytes.
 */
void kscrs_addUserReport(const char* report, int reportLength);

/** Delete all reports on disk.
 */
void kscrs_deleteAllReports();


/** Increment the crash report index.
 * Internal function. Do not use.
 */
void kscrsi_incrementCrashReportIndex();

/** Get the next crash report ID.
 * Internal function. Do not use.
 */
int64_t kscrsi_getNextCrashReportID();

/** Get the next user report ID.
 * Internal function. Do not use.
 */
int64_t kscrsi_getNextUserReportID();
