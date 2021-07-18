library ieee;
use ieee.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component mux41 is
port(
  s1 : in std_logic;
  s0 : in std_logic;
  i0 : in std_logic;
  i1 : in std_logic;
  i2 : in std_logic;
  i3 : in std_logic;
  y : out std_logic);
end component;

signal select1,select0,inp0,inp1,inp2,inp3,output: std_logic;

begin
  DUT: mux41 port map(select1,select0,inp0,inp1,inp2,inp3,output);
  
  process
  begin
    inp0<='0';
    inp1<='1';
    inp2<='0';
    inp3<='1';
    
    select1<='0';
   	select0<='0';
    wait for 1 ns;
    
    select1<='0';
   	select0<='1';
    wait for 1 ns;
    
    select1<='1';
   	select0<='0';
    wait for 1 ns;
    
    select1<='1';
   	select0<='1';
    wait for 1 ns;
    
        
    --clear
    select1<='0';
   	select0<='0';
    wait for 1 ns;
    wait;
    
  end process;
end tb;