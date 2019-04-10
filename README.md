# ACS Hyper-VE

[![License](https://img.shields.io/github/license/Johno-ACSLive/ACS-Messaging.svg)](https://github.com/Johno-ACSLive/ACS-Hyper-VE/blob/master/README.md#license)

The Advanced Computing Services Hyper-V for Emulators solution was designed to prove a common and consistent architecture for the purposes of multi-platform emulation. The C++ Library project provides access to the Microsoft Hyper-V API and will perform any activities required to run a Virtual Machine. The purpose of the .NET Standard Library is to provide a managed interface to any .NET Core / Framework application. Currently there is a .NET Core command line project which consumes the .NET Standard library for the purposes of testing. There will be a WPF project to provide a GUI version.


## History

While many emulators will be developed using an interpreter, some will use high level emulation (HLE) and others dynamic recompilation (AKA DynaRec) or they could use a combination. There are of course other methods but these are the main ways in which emulators are developed. I aim to develop multiple emulator cores in the near future, however, I also wish to provide emulation of some legacy DOS / 16-bit Windows games. In order to provide a common emulation framework for the cores, I developed this project to see if we can leverage the power of Virtual Machines to provide that framework and allow for sandboxing.

The outcomes of this project will be to determine if using a Hypervisor for emulation is beneficial or not in terms of providing a rich and consistent architecture. If it is, then the project will be fully scaled out to support the scenarios above. If not, the project is still useful if someone wishes to develop their own sandboxing / Virtual Machine application and wishes to interface with an existing Hypervisor (this project only supports Microsoft Hyper-V, however, we may support other Hypervisors at a later date depending on the usefullness of the project).

Layout of the solution, you may be wondering why a mix of managed and unmanaged projects. I have never really properly developed in a systems programming language and have always wanted to properly develop in C++ (I do want to get into Rust programming at some stage, may port this over depending on how the project goes). Given the low level nature of emulation and Hypervisors, it made sense that the core interface and low level activities be performed in this library.

On the flip side, high level languages are great for quickly building apps. It made sense that a GUI and command line application for managing low level operations be created in a high level language. I did think about P\Invoking all low level operations. So why did I choose this route?

For one, I wanted to get into a systems programming language. This isn't the only reason, other reasons are because the Hypervisor API's are quite low level and some operations don't quite map into the managed space. There are some things we need to deal with that are low level with regard to the Virtual CPU and to keep with the low level optimisations (performance and memory) it is far easier to manage in this respect using a low level language such as C++.

The code in the solution / projects are quite crude at this point as I only just started it and it's more for protyping at this stage. I will refactor at the right time.


## Getting Started

Right now, you need Visual Studio 2019 as we are using the new C++ compilers along with the Windows 10 SDK for 1809. I believe you will also need the Windows Driver Kit for 1809 (for the C++ project). The 1803 revisions of the Windows 10 SDK and Windows 10 Driver Kit may work, however, I have not tested these.


## Contribute

If you're interested, check how to [Contribute](CONTRIBUTING.md)!


## License

Licensed under Apache License, Version 2.0
