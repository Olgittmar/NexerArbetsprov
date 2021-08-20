import os
import shutil
from conans import ConanFile, CMake, RunEnvironment, tools
from conans.errors import ConanException

class CPlusPlusConan(ConanFile):
    settings = "os","compiler","build_type","arch"
    requires = "gtest/cci.20210126"
    generators = "cmake"
    default_options = {"*:shared": True}
    short_paths = False # Using Python 3.x on win10, short paths unecessary

    def build_requirements(self):
        self.build_requires("cmake/[>=3.18]")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="lib", src="lib")
        self.copy("*.so*", dst="bin", src="lib")
        self.copy("license*", dst="licenses", folder=True, ignore_case=True) # Likely unecessary here
    
    def build(self):
        env_build = RunEnvironment(self) # Needed for Visual studio compiler
        with tools.environment_append(env_build.vars):
            cmake = CMake(self, set_cmake_flags=True)
            if self.should_configure:
                cmake.configure()
            if self.should_build:
                cmake.build()
            if self.should_test:
                cmake.test( output_on_failure=True )
            if self.should_install:
                cmake.install()