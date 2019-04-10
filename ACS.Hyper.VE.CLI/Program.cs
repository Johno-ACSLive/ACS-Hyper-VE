using System;
using ACS.Hyper.VE.Core;
using static ACS.Hyper.VE.Core.ManagedPlatform;

namespace ACS.Hyper.VE.CLI
{
    class Program
    {
        private static ManagedPlatform MP = new ManagedPlatform();
        
        static void Main(string[] args)
        {
            Console.WriteLine("Checking Hypervisor Status!");
            try
            {
                bool IsPresent = MP.IsHypervisorPresentManaged();
                Console.WriteLine("Windows Hypervisor Platform Status: {0}", IsPresent ? "Enabled" : "Disabled");
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Windows Hypervisor Platform status. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Processor Flush Size!");
            try
            {
                byte FlushSize = MP.GetProcessorClFlushSizeManaged();
                Console.WriteLine("Processor Flush Size: {0}", FlushSize);
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Processor Flush Size. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Processor XSave Features!");
            try
            {
                ProcessorXSaveFeatures XSave = MP.GetProcessorXsaveFeaturesManaged();
                Console.WriteLine("XSave XsaveSupport: {0}", XSave.XsaveSupport);
                Console.WriteLine("XSave XsaveoptSupport: {0}", XSave.XsaveoptSupport);
                Console.WriteLine("XSave AvxSupport: {0}", XSave.AvxSupport);
                Console.WriteLine("XSave Avx2Support: {0}", XSave.Avx2Support);
                Console.WriteLine("XSave FmaSupport: {0}", XSave.FmaSupport);
                Console.WriteLine("XSave MpxSupport: {0}", XSave.MpxSupport);
                Console.WriteLine("XSave Avx512Support: {0}", XSave.Avx512Support);
                Console.WriteLine("XSave Avx512DQSupport: {0}", XSave.Avx512DQSupport);
                Console.WriteLine("XSave Avx512CDSupport: {0}", XSave.Avx512CDSupport);
                Console.WriteLine("XSave Avx512BWSupport: {0}", XSave.Avx512BWSupport);
                Console.WriteLine("XSave Avx512VLSupport: {0}", XSave.Avx512VLSupport);
                Console.WriteLine("XSave XsaveCompSupport: {0}", XSave.XsaveCompSupport);
                Console.WriteLine("XSave XsaveSupervisorSupport: {0}", XSave.XsaveSupervisorSupport);
                Console.WriteLine("XSave Xcr1Support: {0}", XSave.Xcr1Support);
                Console.WriteLine("XSave Avx512BitalgSupport: {0}", XSave.Avx512BitalgSupport);
                Console.WriteLine("XSave Avx512IfmaSupport: {0}", XSave.Avx512IfmaSupport);
                Console.WriteLine("XSave Avx512VBmiSupport: {0}", XSave.Avx512VBmiSupport);
                Console.WriteLine("XSave Avx512VBmi2Support: {0}", XSave.Avx512VBmi2Support);
                Console.WriteLine("XSave Avx512VnniSupport: {0}", XSave.Avx512VnniSupport);
                Console.WriteLine("XSave GfniSupport: {0}", XSave.GfniSupport);
                Console.WriteLine("XSave VaesSupport: {0}", XSave.VaesSupport);
                Console.WriteLine("XSave Avx512VPopcntdqSupport: {0}", XSave.Avx512VPopcntdqSupport);
                Console.WriteLine("XSave VpclmulqdqSupport: {0}", XSave.VpclmulqdqSupport);
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Processor XSave Features. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Features!");
            try
            {
                Features CodeFeatures = MP.GetFeaturesManaged();
                Console.WriteLine("Feature PartialUnmap: {0}", CodeFeatures.PartialUnmap);
                Console.WriteLine("Feature LocalApicEmulation: {0}", CodeFeatures.LocalApicEmulation);
                Console.WriteLine("Feature Xsave: {0}", CodeFeatures.Xsave);
                Console.WriteLine("Feature DirtyPageTracking: {0}", CodeFeatures.DirtyPageTracking);
                Console.WriteLine("Feature SpeculationControl: {0}", CodeFeatures.SpeculationControl);
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Features. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Extended VM Exits!");
            try
            {
                ExtendedVMExits VMExits = MP.GetExtendedVMExitsManaged();
                Console.WriteLine("Has VM Exit for X64CpuidExit: {0}", VMExits.X64CpuidExit);
                Console.WriteLine("Has VM Exit for X64MsrExit: {0}", VMExits.X64MsrExit);
                Console.WriteLine("Has VM Exit for ExceptionExit: {0}", VMExits.ExceptionExit);
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Extended VM Exits. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Exit Bitmap!");
            try
            {
                Console.WriteLine("Exit Bitmap value: {0}", MP.GetExceptionExitBitmapManaged());
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Exit Bitmap. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Processor Vendor!");
            try
            {
                Console.WriteLine("Processor Vendor: {0}", MP.GetProcessorVendorManaged());
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Processor Vendor. Error: {0}", Ex.Message);
            }

            Console.WriteLine("Checking Processor Features!");
            try
            {
                ProcessorFeatures Features = MP.GetProcessorFeaturesManaged();
                Console.WriteLine("Processor Features Sse3Support: {0}", Features.Sse3Support);
                Console.WriteLine("Processor Features LahfSahfSupport: {0}", Features.LahfSahfSupport);
                Console.WriteLine("Processor Features Ssse3Support: {0}", Features.Ssse3Support);
                Console.WriteLine("Processor Features Sse4_1Support: {0}", Features.Sse4_1Support);
                Console.WriteLine("Processor Features Sse4_2Support: {0}", Features.Sse4_2Support);
                Console.WriteLine("Processor Features Sse4aSupport: {0}", Features.Sse4aSupport);
                Console.WriteLine("Processor Features XopSupport: {0}", Features.XopSupport);
                Console.WriteLine("Processor Features PopCntSupport: {0}", Features.PopCntSupport);
                Console.WriteLine("Processor Features Cmpxchg16bSupport: {0}", Features.Cmpxchg16bSupport);
                Console.WriteLine("Processor Features Altmovcr8Support: {0}", Features.Altmovcr8Support);
                Console.WriteLine("Processor Features LzcntSupport: {0}", Features.LzcntSupport);
                Console.WriteLine("Processor Features MisAlignSseSupport: {0}", Features.MisAlignSseSupport);
                Console.WriteLine("Processor Features MmxExtSupport: {0}", Features.MmxExtSupport);
                Console.WriteLine("Processor Features Amd3DNowSupport: {0}", Features.Amd3DNowSupport);
                Console.WriteLine("Processor Features ExtendedAmd3DNowSupport: {0}", Features.ExtendedAmd3DNowSupport);
                Console.WriteLine("Processor Features Page1GbSupport: {0}", Features.Page1GbSupport);
                Console.WriteLine("Processor Features AesSupport: {0}", Features.AesSupport);
                Console.WriteLine("Processor Features PclmulqdqSupport: {0}", Features.PclmulqdqSupport);
                Console.WriteLine("Processor Features PcidSupport: {0}", Features.PcidSupport);
                Console.WriteLine("Processor Features Fma4Support: {0}", Features.Fma4Support);
                Console.WriteLine("Processor Features F16CSupport: {0}", Features.F16CSupport);
                Console.WriteLine("Processor Features RdRandSupport: {0}", Features.RdRandSupport);
                Console.WriteLine("Processor Features RdWrFsGsSupport: {0}", Features.RdWrFsGsSupport);
                Console.WriteLine("Processor Features SmepSupport: {0}", Features.SmepSupport);
                Console.WriteLine("Processor Features EnhancedFastStringSupport: {0}", Features.EnhancedFastStringSupport);
                Console.WriteLine("Processor Features Bmi1Support: {0}", Features.Bmi1Support);
                Console.WriteLine("Processor Features Bmi2Support: {0}", Features.Bmi2Support);
                Console.WriteLine("Processor Features MovbeSupport: {0}", Features.MovbeSupport);
                Console.WriteLine("Processor Features Npiep1Support: {0}", Features.Npiep1Support);
                Console.WriteLine("Processor Features DepX87FPUSaveSupport: {0}", Features.DepX87FPUSaveSupport);
                Console.WriteLine("Processor Features RdSeedSupport: {0}", Features.RdSeedSupport);
                Console.WriteLine("Processor Features AdxSupport: {0}", Features.AdxSupport);
                Console.WriteLine("Processor Features IntelPrefetchSupport: {0}", Features.IntelPrefetchSupport);
                Console.WriteLine("Processor Features SmapSupport: {0}", Features.SmapSupport);
                Console.WriteLine("Processor Features HleSupport: {0}", Features.HleSupport);
                Console.WriteLine("Processor Features RtmSupport: {0}", Features.RtmSupport);
                Console.WriteLine("Processor Features RdtscpSupport: {0}", Features.RdtscpSupport);
                Console.WriteLine("Processor Features ClflushoptSupport: {0}", Features.ClflushoptSupport);
                Console.WriteLine("Processor Features ClwbSupport: {0}", Features.ClwbSupport);
                Console.WriteLine("Processor Features ShaSupport: {0}", Features.ShaSupport);
                Console.WriteLine("Processor Features X87PointersSavedSupport: {0}", Features.X87PointersSavedSupport);
                Console.WriteLine("Processor Features InvpcidSupport: {0}", Features.InvpcidSupport);
                Console.WriteLine("Processor Features IbrsSupport: {0}", Features.IbrsSupport);
                Console.WriteLine("Processor Features StibpSupport: {0}", Features.StibpSupport);
                Console.WriteLine("Processor Features IbpbSupport: {0}", Features.IbpbSupport);
                Console.WriteLine("Processor Features SsbdSupport: {0}", Features.SsbdSupport);
                Console.WriteLine("Processor Features FastShortRepMovSupport: {0}", Features.FastShortRepMovSupport);
                Console.WriteLine("Processor Features RdclNo: {0}", Features.RdclNo);
                Console.WriteLine("Processor Features IbrsAllSupport: {0}", Features.IbrsAllSupport);
                Console.WriteLine("Processor Features SsbNo: {0}", Features.SsbNo);
                Console.WriteLine("Processor Features RsbANo: {0}", Features.RsbANo);
            }
            catch (Exception Ex)
            {
                Console.WriteLine("Unable to determine Processor Features. Error: {0}", Ex.Message);
            }
        }
    }
}