#include <iostream>
#include <Windows.h>

int main() {
    const int num_processes = 10;
    const int range_size = 1000;
    const int total_range = 10000;

    for (int i = 0; i < num_processes; ++i) {
        int start = i * range_size + 1;
        int end = (i + 1) * range_size;
        if (end > total_range) {
            end = total_range;
        }

        std::string command_line = "child.exe " + std::to_string(start) + " " + std::to_string(end);

        STARTUPINFO si = { sizeof(STARTUPINFO) };
        si.dwFlags |= STARTF_USESTDHANDLES;

        PROCESS_INFORMATION pi;

        if (!CreateProcess(
                NULL, &command_line[0], NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
            DWORD last_error = GetLastError();
            std::cerr << "Error creating child process. Error code: " << last_error << std::endl;
            return 1;
        }

        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}
