/* Copyright  2016 MediaTek Inc.
 * Author: Nelson Chang <nelson.chang@mediatek.com>
 * Author: Carlos Huang <carlos.huang@mediatek.com>
 * Author: Harry Huang <harry.huang@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef _RAETH_IOCTL_H
#define _RAETH_IOCTL_H

/* ioctl commands */
#define RAETH_SW_IOCTL          0x89F0
#define RAETH_ESW_REG_READ		0x89F1
#define RAETH_ESW_REG_WRITE		0x89F2
#define RAETH_MII_READ			0x89F3
#define RAETH_MII_WRITE			0x89F4
#define RAETH_ESW_INGRESS_RATE		0x89F5
#define RAETH_ESW_EGRESS_RATE		0x89F6
#define RAETH_ESW_PHY_DUMP		0x89F7
#define RAETH_QDMA_REG_READ		0x89F8
#define RAETH_QDMA_REG_WRITE		0x89F9
#define RAETH_QDMA_QUEUE_MAPPING        0x89FA
#define RAETH_QDMA_READ_CPU_CLK         0x89FB
#define RAETH_MII_READ_CL45             0x89FC
#define RAETH_MII_WRITE_CL45            0x89FD
#define RAETH_QDMA_SFQ_WEB_ENABLE       0x89FE
#define RAETH_SET_LAN_IP		0x89FF

/* switch ioctl commands */
#define SW_IOCTL_SET_EGRESS_RATE        0x0000
#define SW_IOCTL_SET_INGRESS_RATE       0x0001
#define SW_IOCTL_SET_VLAN               0x0002
#define SW_IOCTL_DUMP_VLAN              0x0003
#define SW_IOCTL_DUMP_TABLE             0x0004
#define SW_IOCTL_ADD_L2_ADDR            0x0005
#define SW_IOCTL_DEL_L2_ADDR            0x0006
#define SW_IOCTL_ADD_MCAST_ADDR         0x0007
#define SW_IOCTL_DEL_MCAST_ADDR         0x0008
#define SW_IOCTL_DUMP_MIB               0x0009
#define SW_IOCTL_ENABLE_IGMPSNOOP       0x000A
#define SW_IOCTL_DISABLE_IGMPSNOOP      0x000B
#define SW_IOCTL_SET_PORT_TRUNKING      0x000C
#define SW_IOCTL_GET_PORT_TRUNKING      0x000D
#define SW_IOCTL_SET_PORT_MIRROR        0x000E
#define SW_IOCTL_GET_PHY_STATUS         0x000F
#define SW_IOCTL_READ_REG               0x0010
#define SW_IOCTL_WRITE_REG              0x0011

#define REG_ESW_WT_MAC_MFC              0x10
#define REG_ESW_ISC                     0x18
#define REG_ESW_WT_MAC_ATA1             0x74
#define REG_ESW_WT_MAC_ATA2             0x78
#define REG_ESW_WT_MAC_ATWD             0x7C
#define REG_ESW_WT_MAC_ATC              0x80

#define REG_ESW_TABLE_TSRA1		0x84
#define REG_ESW_TABLE_TSRA2		0x88
#define REG_ESW_TABLE_ATRD		0x8C

#define REG_ESW_VLAN_VTCR		0x90
#define REG_ESW_VLAN_VAWD1		0x94
#define REG_ESW_VLAN_VAWD2		0x98

#if defined(CONFIG_MACH_MT7623)
#define REG_ESW_VLAN_ID_BASE		0x100
#else
#define REG_ESW_VLAN_ID_BASE          0x50
#endif
#define REG_ESW_VLAN_MEMB_BASE		0x70
#define REG_ESW_TABLE_SEARCH		0x24
#define REG_ESW_TABLE_STATUS0		0x28
#define REG_ESW_TABLE_STATUS1		0x2C
#define REG_ESW_TABLE_STATUS2		0x30
#define REG_ESW_WT_MAC_AD0		0x34
#define REG_ESW_WT_MAC_AD1		0x38
#define REG_ESW_WT_MAC_AD2		0x3C

/*MT7622 10/100 phy cal*/
#define RAETH_VBG_IEXT_CALIBRATION	0x40
#define RAETH_TXG_R50_CALIBRATION	0x41
#define RAETH_TXG_OFFSET_CALIBRATION	0x42
#define RAETH_TXG_AMP_CALIBRATION	0x43

#if defined(CONFIG_MACH_MT7623)
#define REG_ESW_MAX         0xFC
#else
#define REG_ESW_MAX			0x16C
#endif
#define REG_HQOS_MAX			0x3FFF

struct esw_reg {
	unsigned int off;
	unsigned int val;
};

struct ra_mii_ioctl_data {
	__u32 phy_id;
	__u32 reg_num;
	__u32 val_in;
	__u32 val_out;
	__u32 port_num;
	__u32 dev_addr;
	__u32 reg_addr;
};

struct ra_switch_ioctl_data {
	unsigned int cmd;
	unsigned int on_off;
	unsigned int port;
	unsigned int bw;
	unsigned int vid;
	unsigned int fid;
	unsigned int port_map;
	unsigned int rx_port_map;
	unsigned int tx_port_map;
	unsigned int igmp_query_interval;
	unsigned int reg_addr;
	unsigned int reg_val;
};

struct esw_rate {
	unsigned int on_off;
	unsigned int port;
	unsigned int bw;	/*Mbps */
};
#endif	/* _RAETH_IOCTL_H */
