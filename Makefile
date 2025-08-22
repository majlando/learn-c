SHELL := pwsh

.PHONY: all build test sanitizers clean

all: build

build:
	@pwsh -NoProfile -ExecutionPolicy Bypass -File ./build-all.ps1

test: build
	@echo "All lessons built and validated."

sanitizers:
	@echo "Running sanitizer-enabled builds for selected lessons..."
	@set ENABLE_SANITIZERS=1; pwsh -NoProfile -ExecutionPolicy Bypass -File ./projects/project-14-sanitizers/build.ps1

clean:
	@echo "Cleaning generated actual.txt files"
	@Get-ChildItem -Path .\projects -Recurse -Filter actual.txt -File | Remove-Item -Force
