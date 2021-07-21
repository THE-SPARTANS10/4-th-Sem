library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component dff_with_rst_clr is
port(
  D: in std_logic;
  clk: in std_logic;
  pre: in std_logic;
  clr: in std_logic;
  O: out std_logic
  );
end component;

signal D_in,clk_in,pre_in,clr_in,O_out: std_logic;

begin
  DUT: dff_with_rst_clr port map(D_in,clk_in,pre_in,clr_in,O_out);
  process
    begin
    for i in 1 to 6 loop
        clk_in<='0';
        wait for 1 ns;
        clk_in<='1';
        wait for 1 ns;
      end loop;
      wait;
    end process;
    
    process
      begin
    D_in<='1';
    pre_in<='1';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='1';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='0';
    pre_in<='0';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='1';
    clr_in<='0';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='1';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='0';
    clr_in<='0';
    wait for 1 ns;
    
    D_in<='0';
    pre_in<='1';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='0';
    clr_in<='0';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='1';
    clr_in<='0';
    wait for 1 ns;
    
    D_in<='0';
    pre_in<='1';
    clr_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    pre_in<='0';
    clr_in<='0';
    wait for 1 ns;
    
    D_in<='0';
    pre_in<='0';
    clr_in<='1';
    wait for 1 ns;  
    wait;
  end process;
end tb;