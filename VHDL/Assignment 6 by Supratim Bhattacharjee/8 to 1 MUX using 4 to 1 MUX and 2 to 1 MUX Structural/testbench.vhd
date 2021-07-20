library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component mux81 is
port(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  I4: in std_logic;
  I5: in std_logic;
  I6: in std_logic;
  I7: in std_logic;
  S2: in std_logic;
  S1: in std_logic;
  S0: in std_logic;
  OP: out std_logic;
  );
end component;

signal I0,I1,I2,I3,I4,I5,I6,I7,S2,S1,S0,OP: std_logic;

begin
  DUT: mux81 port map(I0,I1,I2,I3,I4,I5,I6,I7,S2,S1,S0,OP);
  process
    begin
    I0<='1';
    I1<='0';
    I2<='1';
  	I3<='0';
    I4<='0';
    I5<='1';
    I6<='1';
  	I7<='0';
    
    S2<='0';
    s1<='0';
    s0<='0';
    wait for 1 ns;
    
    S2<='0';
    s1<='0';
    s0<='1';
    wait for 1 ns;
    
    S2<='0';
    s1<='1';
    s0<='0';
    wait for 1 ns;
    
    S2<='0';
    s1<='1';
    s0<='1';
    wait for 1 ns;
    
    S2<='1';
    s1<='0';
    s0<='0';
    wait for 1 ns;
    
    S2<='1';
    s1<='0';
    s0<='1';
    wait for 1 ns;
    
    S2<='1';
    s1<='1';
    s0<='0';
    wait for 1 ns;
    
    S2<='1';
    s1<='1';
    s0<='1';
    wait for 1 ns;
    wait;
  end process;
end tb;