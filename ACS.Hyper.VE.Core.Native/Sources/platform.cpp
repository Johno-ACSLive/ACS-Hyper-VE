#include "..\Headers\pch.h"
#include "..\Headers\platform.h"

bool IsHypervisorPresent()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeHypervisorPresent, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return CapabilityBuffer.HypervisorPresent;
		/*std::cout << "Windows Hypervisor Platform Status: " << std::boolalpha << (CapabilityBuffer.HypervisorPresent ? "Enabled" : "Disabled") << std::endl;
		std::cout << "Bytes Written: " << WrittenSize << std::endl;*/
	}
}

Features GetFeatures()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeFeatures, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		Features CodeFeatures;

		CodeFeatures.PartialUnmap = CapabilityBuffer.Features.PartialUnmap;
		CodeFeatures.LocalApicEmulation = CapabilityBuffer.Features.PartialUnmap;
		CodeFeatures.Xsave = CapabilityBuffer.Features.PartialUnmap;
		CodeFeatures.DirtyPageTracking = CapabilityBuffer.Features.PartialUnmap;
		CodeFeatures.SpeculationControl = CapabilityBuffer.Features.PartialUnmap;

		return CodeFeatures;
	}
}

ExtendedVMExits GetExtendedVMExits()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeExtendedVmExits, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ExtendedVMExits VMExits;

		VMExits.X64CpuidExit = CapabilityBuffer.ExtendedVmExits.X64CpuidExit;
		VMExits.X64MsrExit = CapabilityBuffer.ExtendedVmExits.X64MsrExit;
		VMExits.ExceptionExit = CapabilityBuffer.ExtendedVmExits.ExceptionExit;

		return VMExits;
	}
}

UINT64 GetExceptionExitBitmap()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeExceptionExitBitmap, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return CapabilityBuffer.ExceptionExitBitmap;
	}
}

ProcessorVendor GetProcessorVendor()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeProcessorVendor, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ProcessorVendor Vendor;

		switch (CapabilityBuffer.ProcessorVendor)
		{
		case WHV_PROCESSOR_VENDOR::WHvProcessorVendorAmd:
			Vendor = ProcessorVendor::AMD;
			break;
		case WHV_PROCESSOR_VENDOR::WHvProcessorVendorIntel:
			Vendor = ProcessorVendor::Intel;
			break;
		case WHV_PROCESSOR_VENDOR::WHvProcessorVendorHygon:
			Vendor = ProcessorVendor::Hygon;
			break;
		}

		return Vendor;
	}
}

ProcessorFeatures GetProcessorFeatures()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeProcessorFeatures, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ProcessorFeatures Features;

		Features.Sse3Support = CapabilityBuffer.ProcessorFeatures.Sse3Support;
		Features.LahfSahfSupport = CapabilityBuffer.ProcessorFeatures.LahfSahfSupport;
		Features.Ssse3Support = CapabilityBuffer.ProcessorFeatures.Ssse3Support;
		Features.Sse4_1Support = CapabilityBuffer.ProcessorFeatures.Sse4_1Support;
		Features.Sse4_2Support = CapabilityBuffer.ProcessorFeatures.Sse4_2Support;
		Features.Sse4aSupport = CapabilityBuffer.ProcessorFeatures.Sse4aSupport;
		Features.XopSupport = CapabilityBuffer.ProcessorFeatures.XopSupport;
		Features.PopCntSupport = CapabilityBuffer.ProcessorFeatures.PopCntSupport;
		Features.Cmpxchg16bSupport = CapabilityBuffer.ProcessorFeatures.Cmpxchg16bSupport;
		Features.Altmovcr8Support = CapabilityBuffer.ProcessorFeatures.Altmovcr8Support;
		Features.LzcntSupport = CapabilityBuffer.ProcessorFeatures.LzcntSupport;
		Features.MisAlignSseSupport = CapabilityBuffer.ProcessorFeatures.MisAlignSseSupport;
		Features.MmxExtSupport = CapabilityBuffer.ProcessorFeatures.MmxExtSupport;
		Features.Amd3DNowSupport = CapabilityBuffer.ProcessorFeatures.Amd3DNowSupport;
		Features.ExtendedAmd3DNowSupport = CapabilityBuffer.ProcessorFeatures.ExtendedAmd3DNowSupport;
		Features.Page1GbSupport = CapabilityBuffer.ProcessorFeatures.Page1GbSupport;
		Features.AesSupport = CapabilityBuffer.ProcessorFeatures.AesSupport;
		Features.PclmulqdqSupport = CapabilityBuffer.ProcessorFeatures.PclmulqdqSupport;
		Features.PcidSupport = CapabilityBuffer.ProcessorFeatures.PcidSupport;
		Features.Fma4Support = CapabilityBuffer.ProcessorFeatures.Fma4Support;
		Features.F16CSupport = CapabilityBuffer.ProcessorFeatures.F16CSupport;
		Features.RdRandSupport = CapabilityBuffer.ProcessorFeatures.RdRandSupport;
		Features.RdWrFsGsSupport = CapabilityBuffer.ProcessorFeatures.RdWrFsGsSupport;
		Features.SmepSupport = CapabilityBuffer.ProcessorFeatures.SmepSupport;
		Features.EnhancedFastStringSupport = CapabilityBuffer.ProcessorFeatures.EnhancedFastStringSupport;
		Features.Bmi1Support = CapabilityBuffer.ProcessorFeatures.Bmi1Support;
		Features.Bmi2Support = CapabilityBuffer.ProcessorFeatures.Bmi2Support;
		Features.MovbeSupport = CapabilityBuffer.ProcessorFeatures.MovbeSupport;
		Features.Npiep1Support = CapabilityBuffer.ProcessorFeatures.Npiep1Support;
		Features.DepX87FPUSaveSupport = CapabilityBuffer.ProcessorFeatures.DepX87FPUSaveSupport;
		Features.RdSeedSupport = CapabilityBuffer.ProcessorFeatures.RdSeedSupport;
		Features.AdxSupport = CapabilityBuffer.ProcessorFeatures.AdxSupport;
		Features.IntelPrefetchSupport = CapabilityBuffer.ProcessorFeatures.IntelPrefetchSupport;
		Features.SmapSupport = CapabilityBuffer.ProcessorFeatures.SmapSupport;
		Features.HleSupport = CapabilityBuffer.ProcessorFeatures.HleSupport;
		Features.RtmSupport = CapabilityBuffer.ProcessorFeatures.RtmSupport;
		Features.RdtscpSupport = CapabilityBuffer.ProcessorFeatures.RdtscpSupport;
		Features.ClflushoptSupport = CapabilityBuffer.ProcessorFeatures.ClflushoptSupport;
		Features.ClwbSupport = CapabilityBuffer.ProcessorFeatures.ClwbSupport;
		Features.ShaSupport = CapabilityBuffer.ProcessorFeatures.ShaSupport;
		Features.X87PointersSavedSupport = CapabilityBuffer.ProcessorFeatures.X87PointersSavedSupport;
		Features.InvpcidSupport = CapabilityBuffer.ProcessorFeatures.InvpcidSupport;
		Features.IbrsSupport = CapabilityBuffer.ProcessorFeatures.IbrsSupport;
		Features.StibpSupport = CapabilityBuffer.ProcessorFeatures.StibpSupport;
		Features.IbpbSupport = CapabilityBuffer.ProcessorFeatures.IbpbSupport;
		Features.SsbdSupport = CapabilityBuffer.ProcessorFeatures.SsbdSupport;
		Features.FastShortRepMovSupport = CapabilityBuffer.ProcessorFeatures.FastShortRepMovSupport;
		Features.RdclNo = CapabilityBuffer.ProcessorFeatures.RdclNo;
		Features.IbrsAllSupport = CapabilityBuffer.ProcessorFeatures.IbrsAllSupport;
		Features.SsbNo = CapabilityBuffer.ProcessorFeatures.SsbNo;
		Features.RsbANo = CapabilityBuffer.ProcessorFeatures.RsbANo;

		return Features;
	}
}

UINT8 GetProcessorClFlushSize()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeProcessorClFlushSize, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return CapabilityBuffer.ProcessorClFlushSize;
	}
}

ProcessorXSaveFeatures GetProcessorXSaveFeatures()
{
	WHV_CAPABILITY CapabilityBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetCapability(WHvCapabilityCodeProcessorXsaveFeatures, &CapabilityBuffer, sizeof(CapabilityBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ProcessorXSaveFeatures XSave;

		XSave.XsaveSupport = CapabilityBuffer.ProcessorXsaveFeatures.XsaveSupport;
		XSave.XsaveoptSupport = CapabilityBuffer.ProcessorXsaveFeatures.XsaveoptSupport;
		XSave.AvxSupport = CapabilityBuffer.ProcessorXsaveFeatures.AvxSupport;
		XSave.Avx2Support = CapabilityBuffer.ProcessorXsaveFeatures.Avx2Support;
		XSave.FmaSupport = CapabilityBuffer.ProcessorXsaveFeatures.FmaSupport;
		XSave.MpxSupport = CapabilityBuffer.ProcessorXsaveFeatures.MpxSupport;
		XSave.Avx512Support = CapabilityBuffer.ProcessorXsaveFeatures.Avx512Support;
		XSave.Avx512DQSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512DQSupport;
		XSave.Avx512CDSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512CDSupport;
		XSave.Avx512BWSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512BWSupport;
		XSave.Avx512VLSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512VLSupport;
		XSave.XsaveCompSupport = CapabilityBuffer.ProcessorXsaveFeatures.XsaveCompSupport;
		XSave.XsaveSupervisorSupport = CapabilityBuffer.ProcessorXsaveFeatures.XsaveSupervisorSupport;
		XSave.Xcr1Support = CapabilityBuffer.ProcessorXsaveFeatures.Xcr1Support;
		XSave.Avx512BitalgSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512BitalgSupport;
		XSave.Avx512IfmaSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512IfmaSupport;
		XSave.Avx512VBmiSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512VBmiSupport;
		XSave.Avx512VBmi2Support = CapabilityBuffer.ProcessorXsaveFeatures.Avx512VBmi2Support;
		XSave.Avx512VnniSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512VnniSupport;
		XSave.GfniSupport = CapabilityBuffer.ProcessorXsaveFeatures.GfniSupport;
		XSave.VaesSupport = CapabilityBuffer.ProcessorXsaveFeatures.VaesSupport;
		XSave.Avx512VPopcntdqSupport = CapabilityBuffer.ProcessorXsaveFeatures.Avx512VPopcntdqSupport;
		XSave.VpclmulqdqSupport = CapabilityBuffer.ProcessorXsaveFeatures.VpclmulqdqSupport;

		return XSave;
	}
}