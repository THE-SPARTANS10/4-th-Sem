library ieee;
use ieee.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component mux41 is
port
(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  S0: in std_logic;
  S1: in std_logic;
  Y: out std_logic;
);
end component;

signal i0_in,i1_in,i2_in,i3_in,s0_in,s1_in,y_out: std_logic;

begin
  DUT: mux41 port map(i0_in,i1_in,i2_in,i3_in,s0_in,s1_in,y_out);
  process
  begin
    i0_in<='1';
    i1_in<='0';
    i2_in<='1';
    i3_in<='0';
    
    s1_in<='0';
    s0_in<='0';
    wait for 1 ns;
    
    s1_in<='0';
    s0_in<='1';
    wait for 1 ns;
    
    s1_in<='1';
    s0_in<='0';
    wait for 1 ns;
    
    s1_in<='1';
    s0_in<='1';
    wait for 1 ns;
    wait;
  end process;
end tb;