function M= my_new_module(NAME)
% M = my_new_module(NAME)
% Copies input pin data to the output pin.
%
% Arguments:
% NAME - name of the module
%

% AudioWeaverModule [This tag makes it appear under awe_help]

M=awe_module('MyNew', 'Copies input wire to output wire');
if (nargin == 0)
 return;
end

M.name=NAME;
M.defaultName='MyNew';

% Add input and output pins with no data or size restrictions
PT=new_pin_type([], [], [], '*32', []);
add_pin(M, 'input', 'in', 'Input signal', PT);
add_pin(M, 'output', 'out', 'Output signal', PT);

add_variable(M, 'currentFrame', 'int', 0, 'parameter', 'current frame number', 1);

% ----------------------------------------------------------------------
% Code generation details
% ----------------------------------------------------------------------
awe_addcodemarker(M, 'processFunction', 'Insert:\InnerMyNew_Process.c');
awe_addcodemarker(M, 'postConstructorFunction', 'Insert:\InnerMyNew_postConstructor.c');
awe_addcodemarker(M, 'hFileInclude', '#include <windows.h>');
awe_addcodemarker(M, 'hFileInclude', '#include "../source/file_logger.h"');
awe_addcodemarker(M, 'hFileDefine', '#define MYNEW_VERSION_STRING "0.1.0"');
awe_addcodemarker(M, 'hFileDefine', 'DWORD WINAPI threadProc(LPVOID lpParameter);');
awe_addcodemarker(M, 'srcFileDefine', 'HANDLE threadHandle;');
awe_addcodemarker(M, 'srcFileDefine', 'volatile BOOL threadRunning;');
awe_addcodemarker(M, 'srcFileDefine', 'CRITICAL_SECTION cs;');
awe_addcodemarker(M, 'srcFileDefine', 'DWORD WINAPI threadProc(LPVOID lpParam) { for(awe_modMyNewInstance* S=lpParam; threadRunning; Sleep(170)) { LARGE_INTEGER t; QueryPerformanceCounter(&t); EnterCriticalSection(&cs); LOGI("Frame:%d Time:%lld", S->currentFrame, t.QuadPart); LeaveCriticalSection(&cs); } return 0; }');
awe_addcodemarker(M, 'discussion', {'Copies the input to the output. '});

% ----------------------------------------------------------------------
% Module browser information
% ----------------------------------------------------------------------
M.moduleBrowser.path = 'Third Party';
M.moduleBrowser.image = '../images/MyNew.bmp';
M.moduleBrowser.searchTags = 'pass thru through copy';
return;
