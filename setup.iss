[Setup]
AppName=MyApp
AppVersion=1.0
DefaultDirName={pf}\VU\Sarunas-Gikys
DefaultGroupName=MyApp
OutputDir=.
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Files]
Source: "C:\Users\sgiky\Documents\GitHub\OBJ_Uzduotys3\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\MyApp"; Filename: "{app}\Student_Grades.exe"
Name: "{userdesktop}\MyApp"; Filename: "{app}\Student_Grades.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; Flags: unchecked