NewSRT
======


Introduction
------------

The Small Radio Telescope was developed by Haystack Observatory to serve as an educational
tool for universities and colleges for teaching astronomy and radio technology. The
original SRT was popular, with several hundred being built and is still in use at many
colleges. It is no longer available new, however, and advances in electronics have
rendered the original obsolete. Development of a new SRT was undertaken by Haystack in 
summer 2012.

The primary philosophy of this new design for the SRT is that the users should build the
telescope themselves from commercially available equipment, based on plans, instructions,
and software provided by Haystack. It is designed to be assembled easily with minimal need
for special tools or skills. This approach provides an educational opportunity to the
users who build the telescope. Also, users of the SRT will be more familiar with how it
works if they assemble it themselves, allowing better in-house technical assistance.

Main site: https://wikis.mit.edu/confluence/display/SRT/SRT+Wiki+Home


Details
-------


The current source includes c-code for the "new" SRT using:

   1. DAS-4020 PCI bus ADC card and in this caseyou need to install the
      driver PCI-DAS4020-12.1.21.tgz
   2. DVB-T dongle with Rafael R820T tuner and Realtek RTL2832U uses c code mostly
      from RTLSDR
   3. Software FFT
   4. Fast FFT for amd or intel processors
   5. FDI/USB code for AlfaRadio rot2 SPID antenna controller

The software is compiled using gcc by the bash script srtnmake
Uncomment the gcc line which matches your available hardware
Note that the libraries specified on this line need to be installed
for the compilation to complete without errors. 

The simplest version (last option in srtnmake script) which uses the TV dongle and
a software FFT is recommended. Given the narrow bandwidth of the dongle compared with
the PCI-DAS4020 the software FFT speed on most new PCs is quite satisfactory.  

The version fixes a possible hanging of the rot2Prog controller. Fixes bswpwr
readout in beamswitch mode. New features added are ability to use a stow position
away from limits using keyword STOWPOS. Added record option which clears accumulation 
record using RCLR. Selection of a time for simulation using
START_DATE. Added keyword "vplot" to allow the generation of Postscript plot files 
during the execution of a command file. Some general improvement to help display clarity.
Many corrections and additions to the srt.hlp file.

Alan Rogers and Daniel Leonard  8 Sept 2014

Added notes:

   1. DAS-4020 PCI bus ADC card

    Go through the pci-das4020-12/README file 

    Then edit ADC_BUFF_PHY_SIZE accordingly in a2dc.h, to set the DMA
    Buffer Size FOR EACH BOARD  and if a2dc.h is not edited

    /* Note:  Edit these values for your particular system.  See README  */
    #define ADC_BUFF_PHY_SIZE   0x0200000  // Physical size of the ADCs buffer
    #define ADC_BUFF_PAGE_SIZE  0x0200000  /* must be a multiple of PAGE_SIZE and HALF_FIFO_SIZE and 
                                              greater than or equal to PAGE_SIZE.
                                              changed to 0x0200000 AEER
   2. AMD FFT

    The following files library files may be required (and are included)
    if the ones on the PC are not compatible:

    libacml.so
    libgfortran.a

   3. Intel FFT

    Obtain fftw from www.fftw.org download fftw-3.3.3.tar.gz
    and install using float precision

   4. In order to run as user 

      - FDI/USB make user member of dialout group
      - DAS-4020 copy over udev rules
      - install the udev rules file rtl-sdr.rules 
  
   5. Old Cassicorp antenna controller

    This new release does not support the old Cassicorp antenna controller but I have
    included the old code (sportold.c) which might be useful for anyone who wants to write
    code for this old controller.
 
   6. The TV dongle is recommended

    If you use the TV dongle all the source code is in the tar ball and it is easy to use
    grep to find variables etc. in the code and *.h files, make changes or add a printf
    for  debugging a problem and recompile. Please send any code corrections that may be
    or general use to Haystack for possible inclusion in the next release  
