library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component encoder42 is
port(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  O0: out std_logic;
  O1: out std_logic;
  );
end component;

signal i0_in,i1_in,i2_in,i3_in,o0_out,o1_out: std_logic;

begin
  DUT: encoder42 port map(i0_in,i1_in,i2_in,i3_in,o0_out,o1_out);
  process
    begin
    i0_in<='1';
    i1_in<='0';
    i2_in<='0';
    i3_in<='0';
    wait for 1 ns;
    
    i0_in<='0';
    i1_in<='1';
    i2_in<='0';
    i3_in<='0';
    wait for 1 ns;
    
    i0_in<='0';
    i1_in<='0';
    i2_in<='1';
    i3_in<='0';
    wait for 1 ns;
    
    i0_in<='0';
    i1_in<='0';
    i2_in<='0';
    i3_in<='1';
    wait for 1 ns;
    wait;
end process;
end tb;