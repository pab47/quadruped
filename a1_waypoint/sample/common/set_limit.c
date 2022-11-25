double set_limit(double val, double val_max)
{
if (val>val_max)
{
  val = val_max;
}
else if (val<-val_max)
{
  val = -val_max;
}

return val;

}
