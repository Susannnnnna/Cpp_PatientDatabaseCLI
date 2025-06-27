# Patient Database CLI
## Objective
CLI application to store patient data in csv file and patient results.

## Key results
- Patients data stored in .csv file
- Possibility to add, edit, delete patients data
- Pssibility to read patients results
- Unit, integration, system and regression Tests
- TDD
- CI/CD

## Content
- [App examples](./README.md#app-examples)
- [How to run the app?](./README.md#how-to-run-the-app)
  - [Environment](./README.md#environment)
  - [Used technologies](./README.md#used-technologies)
  - [Database and data](./README.md#database-and-data)
  - [Run the app](./README.md#run-the-app)
- [Testing](./README.md#testing)
- [License](./README.md#license)

## App examples

## How to run the app?
### Environment
- Tested on Windows 11

### Used technologies
- Visual Studio Code
- C++
- CMake 
- GoogleTest
- Powershell
- JSON

### Database and data
Add patient data to .csv database via command line.
Storing patient test results in a separate .txt file.

### Run the app
Download files from GitHub
```
git clone https://github.com/Susannnnnna/Cpp_PatientDatabaseCLI
```
Needed installations in Visual Studio Code:
Install extensions:
- GitHub.vscode-pull-request-github
- jenkins-pipeline-linter-connector
- redhat.vscode-yaml???

Run the app by using Ctr+Shift+B

```
cd path\to\your\project\build cmake --build . --config Debug
```

## Testing
Description available in: tests/README.md

## License
[MIT license](https://opensource.org/licenses/MIT)