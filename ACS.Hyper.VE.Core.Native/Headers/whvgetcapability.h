#pragma once

extern "C"
{
	typedef struct Features
	{
		bool PartialUnmap;
		bool LocalApicEmulation;
		bool Xsave;
		bool DirtyPageTracking;
		bool SpeculationControl;
	} Features;

	typedef struct ExtendedVMExits
	{
		bool X64CpuidExit;
		bool X64MsrExit;
		bool ExceptionExit;
	} ExtendedVMExits;

	typedef enum ProcessorVendor
	{
		AMD = 0x0000,
		Intel = 0x0001,
		Hygon = 0x0002
	} ProcessorVendor;

	typedef struct ProcessorFeatures
	{
		bool Sse3Support;
		bool LahfSahfSupport;
		bool Ssse3Support;
		bool Sse4_1Support;
		bool Sse4_2Support;
		bool Sse4aSupport;
		bool XopSupport;
		bool PopCntSupport;
		bool Cmpxchg16bSupport;
		bool Altmovcr8Support;
		bool LzcntSupport;
		bool MisAlignSseSupport;
		bool MmxExtSupport;
		bool Amd3DNowSupport;
		bool ExtendedAmd3DNowSupport;
		bool Page1GbSupport;
		bool AesSupport;
		bool PclmulqdqSupport;
		bool PcidSupport;
		bool Fma4Support;
		bool F16CSupport;
		bool RdRandSupport;
		bool RdWrFsGsSupport;
		bool SmepSupport;
		bool EnhancedFastStringSupport;
		bool Bmi1Support;
		bool Bmi2Support;
		bool MovbeSupport;
		bool Npiep1Support;
		bool DepX87FPUSaveSupport;
		bool RdSeedSupport;
		bool AdxSupport;
		bool IntelPrefetchSupport;
		bool SmapSupport;
		bool HleSupport;
		bool RtmSupport;
		bool RdtscpSupport;
		bool ClflushoptSupport;
		bool ClwbSupport;
		bool ShaSupport;
		bool X87PointersSavedSupport;
		bool InvpcidSupport;
		bool IbrsSupport;
		bool StibpSupport;
		bool IbpbSupport;
		bool SsbdSupport;
		bool FastShortRepMovSupport;
		bool RdclNo;
		bool IbrsAllSupport;
		bool SsbNo;
		bool RsbANo;
	} ProcessorFeatures;

	typedef struct ProcessorXSaveFeatures
	{
		bool XsaveSupport;
		bool XsaveoptSupport;
		bool AvxSupport;
		bool Avx2Support;
		bool FmaSupport;
		bool MpxSupport;
		bool Avx512Support;
		bool Avx512DQSupport;
		bool Avx512CDSupport;
		bool Avx512BWSupport;
		bool Avx512VLSupport;
		bool XsaveCompSupport;
		bool XsaveSupervisorSupport;
		bool Xcr1Support;
		bool Avx512BitalgSupport;
		bool Avx512IfmaSupport;
		bool Avx512VBmiSupport;
		bool Avx512VBmi2Support;
		bool Avx512VnniSupport;
		bool GfniSupport;
		bool VaesSupport;
		bool Avx512VPopcntdqSupport;
		bool VpclmulqdqSupport;
	} ProcessorXSaveFeatures;

	__declspec(dllexport) bool IsHypervisorPresent();
	__declspec(dllexport) Features GetFeatures();
	__declspec(dllexport) ExtendedVMExits GetExtendedVMExits();
	__declspec(dllexport) UINT64 GetExceptionExitBitmap();
	__declspec(dllexport) ProcessorVendor GetProcessorVendor();
	__declspec(dllexport) ProcessorFeatures GetProcessorFeatures();
	__declspec(dllexport) UINT8 GetProcessorClFlushSize();
	__declspec(dllexport) ProcessorXSaveFeatures GetProcessorXSaveFeatures();
}