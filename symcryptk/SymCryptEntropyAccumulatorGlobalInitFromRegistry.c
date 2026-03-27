__int64 SymCryptEntropyAccumulatorGlobalInitFromRegistry()
{
  __int64 result; // rax

  if ( !g_SymCryptEntropyAccumulatorConfig )
    return SymCryptEntropyAccumulatorReadConfig();
  return result;
}
