project new D:/Digilent/Projects/Atlys/Atlys_12_2_RevC_BIST/pcores/d_usb_epp_dstm_v1_00_a/devl/projnav/d_usb_epp_dstm.xise;
project set family spartan6;
project set device xc6slx45;
project set package csg324;
project set speed -2;
project set top_level_module_type HDL;
project set synthesis_tool "XST (VHDL/Verilog)";
lib_vhdl new d_usb_epp_dstm_v1_00_a;
xfile add D:/Digilent/Projects/Atlys/Atlys_12_2_RevC_BIST/pcores/d_usb_epp_dstm_v1_00_a/hdl/vhdl/d_usb_epp_dstm.vhd -lib_vhdl d_usb_epp_dstm_v1_00_a;
xfile add D:/Digilent/Projects/Atlys/Atlys_12_2_RevC_BIST/pcores/d_usb_epp_dstm_v1_00_a/hdl/vhdl/user_logic.vhd -lib_vhdl d_usb_epp_dstm_v1_00_a;
lib_vhdl new proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/proc_common_pkg.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/ipif_pkg.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/or_muxcy.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/or_gate128.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/family_support.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/pselect_f.vhd -lib_vhdl proc_common_v3_00_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/proc_common_v3_00_a/hdl/vhdl/counter_f.vhd -lib_vhdl proc_common_v3_00_a;
lib_vhdl new plbv46_slave_single_v1_01_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plb_address_decoder.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plb_slave_attachment.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
xfile add M:/Xilinx/12.2/ISE_DS/EDK/hw/XilinxProcessorIPLib/pcores/plbv46_slave_single_v1_01_a/hdl/vhdl/plbv46_slave_single.vhd -lib_vhdl plbv46_slave_single_v1_01_a;
project close;