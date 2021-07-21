library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component dff is
port(
  D: in std_logic;
  clk: in std_logic;
  O: out std_logic
  );
end component;

signal D_in,clk_in,O_out: std_logic;

begin
  DUT: dff port map(D_in,clk_in,O_out);
  process
    begin
      for i in 1 to 4 loop
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
    wait for 1 ns;
    
    D_in<='0';
    wait for 1 ns;
    
    D_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    wait for 1 ns;
    
    D_in<='1';
    wait for 1 ns;
    
    D_in<='0';
    wait for 1 ns;
    
    D_in<='1';
    wait for 1 ns;
    
    D_in<='0';
    wait for 1 ns;
    wait;
  end process;
end tb;
