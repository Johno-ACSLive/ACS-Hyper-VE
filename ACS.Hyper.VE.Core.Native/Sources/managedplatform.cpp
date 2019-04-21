#include "..\Headers\pch.h"
#include "..\Headers\managedplatform.h"

WHV_PARTITION_HANDLE Partition;

#pragma region GetCapability

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
		default:
			throw "Vendor not Found!";
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

#pragma endregion

#pragma region GetPartitionCounters

PartitionMemoryCounters GetPartitionCounters()
{
	WHV_PARTITION_MEMORY_COUNTERS CountersBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionCounters(&Partition, WHV_PARTITION_COUNTER_SET::WHvPartitionCounterSetMemory, &CountersBuffer, sizeof(CountersBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		PartitionMemoryCounters Counters;

		Counters.Mapped4KPageCount = CountersBuffer.Mapped4KPageCount;
		Counters.Mapped2MPageCount = CountersBuffer.Mapped2MPageCount;
		Counters.Mapped1GPageCount = CountersBuffer.Mapped1GPageCount;

		return Counters;
	}
}

#pragma endregion

#pragma region GetPartitionProperty

ExtendedVMExits GetPartitionExtendedVmExits()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeExtendedVmExits, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ExtendedVMExits VMExits;

		VMExits.X64CpuidExit = PartitionPropertyBuffer.ExtendedVmExits.X64CpuidExit;
		VMExits.X64MsrExit = PartitionPropertyBuffer.ExtendedVmExits.X64MsrExit;
		VMExits.ExceptionExit = PartitionPropertyBuffer.ExtendedVmExits.ExceptionExit;

		return VMExits;
	}
}

UINT64 GetPartitionExceptionExitBitmap()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeExceptionExitBitmap, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return PartitionPropertyBuffer.ExceptionExitBitmap;
	}
}

bool GetPartitionSeparateSecurityDomain()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeSeparateSecurityDomain, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return PartitionPropertyBuffer.SeparateSecurityDomain;
	}
}

ProcessorFeatures GetProcessorFeatures()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeProcessorFeatures, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		ProcessorFeatures Features;

		Features.Sse3Support = PartitionPropertyBuffer.ProcessorFeatures.Sse3Support;
		Features.LahfSahfSupport = PartitionPropertyBuffer.ProcessorFeatures.LahfSahfSupport;
		Features.Ssse3Support = PartitionPropertyBuffer.ProcessorFeatures.Ssse3Support;
		Features.Sse4_1Support = PartitionPropertyBuffer.ProcessorFeatures.Sse4_1Support;
		Features.Sse4_2Support = PartitionPropertyBuffer.ProcessorFeatures.Sse4_2Support;
		Features.Sse4aSupport = PartitionPropertyBuffer.ProcessorFeatures.Sse4aSupport;
		Features.XopSupport = PartitionPropertyBuffer.ProcessorFeatures.XopSupport;
		Features.PopCntSupport = PartitionPropertyBuffer.ProcessorFeatures.PopCntSupport;
		Features.Cmpxchg16bSupport = PartitionPropertyBuffer.ProcessorFeatures.Cmpxchg16bSupport;
		Features.Altmovcr8Support = PartitionPropertyBuffer.ProcessorFeatures.Altmovcr8Support;
		Features.LzcntSupport = PartitionPropertyBuffer.ProcessorFeatures.LzcntSupport;
		Features.MisAlignSseSupport = PartitionPropertyBuffer.ProcessorFeatures.MisAlignSseSupport;
		Features.MmxExtSupport = PartitionPropertyBuffer.ProcessorFeatures.MmxExtSupport;
		Features.Amd3DNowSupport = PartitionPropertyBuffer.ProcessorFeatures.Amd3DNowSupport;
		Features.ExtendedAmd3DNowSupport = PartitionPropertyBuffer.ProcessorFeatures.ExtendedAmd3DNowSupport;
		Features.Page1GbSupport = PartitionPropertyBuffer.ProcessorFeatures.Page1GbSupport;
		Features.AesSupport = PartitionPropertyBuffer.ProcessorFeatures.AesSupport;
		Features.PclmulqdqSupport = PartitionPropertyBuffer.ProcessorFeatures.PclmulqdqSupport;
		Features.PcidSupport = PartitionPropertyBuffer.ProcessorFeatures.PcidSupport;
		Features.Fma4Support = PartitionPropertyBuffer.ProcessorFeatures.Fma4Support;
		Features.F16CSupport = PartitionPropertyBuffer.ProcessorFeatures.F16CSupport;
		Features.RdRandSupport = PartitionPropertyBuffer.ProcessorFeatures.RdRandSupport;
		Features.RdWrFsGsSupport = PartitionPropertyBuffer.ProcessorFeatures.RdWrFsGsSupport;
		Features.SmepSupport = PartitionPropertyBuffer.ProcessorFeatures.SmepSupport;
		Features.EnhancedFastStringSupport = PartitionPropertyBuffer.ProcessorFeatures.EnhancedFastStringSupport;
		Features.Bmi1Support = PartitionPropertyBuffer.ProcessorFeatures.Bmi1Support;
		Features.Bmi2Support = PartitionPropertyBuffer.ProcessorFeatures.Bmi2Support;
		Features.MovbeSupport = PartitionPropertyBuffer.ProcessorFeatures.MovbeSupport;
		Features.Npiep1Support = PartitionPropertyBuffer.ProcessorFeatures.Npiep1Support;
		Features.DepX87FPUSaveSupport = PartitionPropertyBuffer.ProcessorFeatures.DepX87FPUSaveSupport;
		Features.RdSeedSupport = PartitionPropertyBuffer.ProcessorFeatures.RdSeedSupport;
		Features.AdxSupport = PartitionPropertyBuffer.ProcessorFeatures.AdxSupport;
		Features.IntelPrefetchSupport = PartitionPropertyBuffer.ProcessorFeatures.IntelPrefetchSupport;
		Features.SmapSupport = PartitionPropertyBuffer.ProcessorFeatures.SmapSupport;
		Features.HleSupport = PartitionPropertyBuffer.ProcessorFeatures.HleSupport;
		Features.RtmSupport = PartitionPropertyBuffer.ProcessorFeatures.RtmSupport;
		Features.RdtscpSupport = PartitionPropertyBuffer.ProcessorFeatures.RdtscpSupport;
		Features.ClflushoptSupport = PartitionPropertyBuffer.ProcessorFeatures.ClflushoptSupport;
		Features.ClwbSupport = PartitionPropertyBuffer.ProcessorFeatures.ClwbSupport;
		Features.ShaSupport = PartitionPropertyBuffer.ProcessorFeatures.ShaSupport;
		Features.X87PointersSavedSupport = PartitionPropertyBuffer.ProcessorFeatures.X87PointersSavedSupport;
		Features.InvpcidSupport = PartitionPropertyBuffer.ProcessorFeatures.InvpcidSupport;
		Features.IbrsSupport = PartitionPropertyBuffer.ProcessorFeatures.IbrsSupport;
		Features.StibpSupport = PartitionPropertyBuffer.ProcessorFeatures.StibpSupport;
		Features.IbpbSupport = PartitionPropertyBuffer.ProcessorFeatures.IbpbSupport;
		Features.SsbdSupport = PartitionPropertyBuffer.ProcessorFeatures.SsbdSupport;
		Features.FastShortRepMovSupport = PartitionPropertyBuffer.ProcessorFeatures.FastShortRepMovSupport;
		Features.RdclNo = PartitionPropertyBuffer.ProcessorFeatures.RdclNo;
		Features.IbrsAllSupport = PartitionPropertyBuffer.ProcessorFeatures.IbrsAllSupport;
		Features.SsbNo = PartitionPropertyBuffer.ProcessorFeatures.SsbNo;
		Features.RsbANo = PartitionPropertyBuffer.ProcessorFeatures.RsbANo;

		return Features;
	}
}

UINT8 GetProcessorClFlushSize()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeProcessorClFlushSize, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		return PartitionPropertyBuffer.ProcessorClFlushSize;
	}
}

CPUIDExit GetProcessorCPUIDExitList()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeCpuidExitList, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		CPUIDExit EL;

		EL.List[0] = PartitionPropertyBuffer.CpuidExitList[0];
		return EL;
	}
}

CPUIDResult GetProcessorCPUIDResultList()
{
	WHV_PARTITION_PROPERTY PartitionPropertyBuffer;
	UINT32 WrittenSize;

	auto hr = WHvGetPartitionProperty(&Partition, WHvPartitionPropertyCodeCpuidResultList, &PartitionPropertyBuffer, sizeof(PartitionPropertyBuffer), &WrittenSize);

	if (FAILED(hr))
	{
		throw hr;
	}
	else
	{
		CPUIDResult RL;

		RL.Function = PartitionPropertyBuffer.CpuidResultList[0].Function;
		RL.Eax = PartitionPropertyBuffer.CpuidResultList[0].Eax;
		RL.Ebx = PartitionPropertyBuffer.CpuidResultList[0].Ebx;
		RL.Ecx = PartitionPropertyBuffer.CpuidResultList[0].Ecx;
		RL.Edx = PartitionPropertyBuffer.CpuidResultList[0].Edx;

		return RL;
	}
}

#pragma endregion
//typedef enum {
//	WHvPartitionPropertyCodeLocalApicEmulationMode = 0x00001005,
//	WHvPartitionPropertyCodeProcessorXsaveFeatures = 0x00001006,
//
//	WHvPartitionPropertyCodeProcessorCount = 0x00001fff
//} WHV_PARTITION_PROPERTY_CODE;
