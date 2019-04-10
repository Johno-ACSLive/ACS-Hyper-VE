using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace ACS.Hyper.VE.Core
{
    public class ManagedPlatform
    {
        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern bool IsHypervisorPresent();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern byte GetProcessorClFlushSize();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern ProcessorXSaveFeatures GetProcessorXSaveFeatures();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern Features GetFeatures();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern ExtendedVMExits GetExtendedVMExits();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern ulong GetExceptionExitBitmap();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern ProcessorVendor GetProcessorVendor();

        [DllImport("ACS.Hyper.VE.Core.Native.dll")]
        private static extern ProcessorFeatures GetProcessorFeatures();

        public bool IsHypervisorPresentManaged()
        {
            return IsHypervisorPresent();
        }

        public byte GetProcessorClFlushSizeManaged()
        {
            return GetProcessorClFlushSize();
        }

        public ProcessorXSaveFeatures GetProcessorXsaveFeaturesManaged()
        {
            return GetProcessorXSaveFeatures();
        }

        public Features GetFeaturesManaged()
        {
            return GetFeatures();
        }

        public ExtendedVMExits GetExtendedVMExitsManaged()
        {
            return GetExtendedVMExits();
        }

        public ulong GetExceptionExitBitmapManaged()
        {
            return GetExceptionExitBitmap();
        }

        public ProcessorVendor GetProcessorVendorManaged()
        {
            return GetProcessorVendor();
        }

        public ProcessorFeatures GetProcessorFeaturesManaged()
        {
            return GetProcessorFeatures();
        }

        [StructLayout(LayoutKind.Sequential)]
        public class ProcessorXSaveFeatures
        {
            public bool XsaveSupport;
            public bool XsaveoptSupport;
            public bool AvxSupport;
            public bool Avx2Support;
            public bool FmaSupport;
            public bool MpxSupport;
            public bool Avx512Support;
            public bool Avx512DQSupport;
            public bool Avx512CDSupport;
            public bool Avx512BWSupport;
            public bool Avx512VLSupport;
            public bool XsaveCompSupport;
            public bool XsaveSupervisorSupport;
            public bool Xcr1Support;
            public bool Avx512BitalgSupport;
            public bool Avx512IfmaSupport;
            public bool Avx512VBmiSupport;
            public bool Avx512VBmi2Support;
            public bool Avx512VnniSupport;
            public bool GfniSupport;
            public bool VaesSupport;
            public bool Avx512VPopcntdqSupport;
            public bool VpclmulqdqSupport;
        }

        [StructLayout(LayoutKind.Sequential)]
        public class Features
        {
            public bool PartialUnmap;
            public bool LocalApicEmulation;
            public bool Xsave;
            public bool DirtyPageTracking;
            public bool SpeculationControl;

        }

        [StructLayout(LayoutKind.Sequential)]
        public class ExtendedVMExits
        {
            public bool X64CpuidExit;
            public bool X64MsrExit;
            public bool ExceptionExit;

        }

        public enum ProcessorVendor
        {
            AMD = 0x0000,
            Intel = 0x0001,
            Hygon = 0x0002
        }

        [StructLayout(LayoutKind.Sequential)]
        public class ProcessorFeatures
        {
            public bool Sse3Support;
            public bool LahfSahfSupport;
            public bool Ssse3Support;
            public bool Sse4_1Support;
            public bool Sse4_2Support;
            public bool Sse4aSupport;
            public bool XopSupport;
            public bool PopCntSupport;
            public bool Cmpxchg16bSupport;
            public bool Altmovcr8Support;
            public bool LzcntSupport;
            public bool MisAlignSseSupport;
            public bool MmxExtSupport;
            public bool Amd3DNowSupport;
            public bool ExtendedAmd3DNowSupport;
            public bool Page1GbSupport;
            public bool AesSupport;
            public bool PclmulqdqSupport;
            public bool PcidSupport;
            public bool Fma4Support;
            public bool F16CSupport;
            public bool RdRandSupport;
            public bool RdWrFsGsSupport;
            public bool SmepSupport;
            public bool EnhancedFastStringSupport;
            public bool Bmi1Support;
            public bool Bmi2Support;
            public bool MovbeSupport;
            public bool Npiep1Support;
            public bool DepX87FPUSaveSupport;
            public bool RdSeedSupport;
            public bool AdxSupport;
            public bool IntelPrefetchSupport;
            public bool SmapSupport;
            public bool HleSupport;
            public bool RtmSupport;
            public bool RdtscpSupport;
            public bool ClflushoptSupport;
            public bool ClwbSupport;
            public bool ShaSupport;
            public bool X87PointersSavedSupport;
            public bool InvpcidSupport;
            public bool IbrsSupport;
            public bool StibpSupport;
            public bool IbpbSupport;
            public bool SsbdSupport;
            public bool FastShortRepMovSupport;
            public bool RdclNo;
            public bool IbrsAllSupport;
            public bool SsbNo;
            public bool RsbANo;
        }
    }
}
