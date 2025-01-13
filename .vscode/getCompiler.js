const vscode = require('vscode');

function getCompiler() {
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
        return os.platform() === 'win32' ? "C:\\software\\mingw64\\bin\\g++.exe" : "/usr/bin/g++"; // 默认使用 g++
    }

    const document = editor.document;
    const extension = document.fileName.split('.').pop().toLowerCase();

    if (['cpp', 'cc', 'cxx'].includes(extension)) {
        return os.platform() === 'win32' ? "C:\\software\\mingw64\\bin\\g++.exe" : "/usr/bin/g++";
    } else if (['c'].includes(extension)) {
        return os.platform() === 'win32' ? "C:\\software\\mingw64\\bin\\gcc.exe" : "/usr/bin/gcc";
    } else {
        return os.platform() === 'win32' ? "C:\\software\\mingw64\\bin\\g++.exe" : "/usr/bin/g++"; // 默认使用 g++
    }
}

module.exports = {
    getCompiler
};