type amazonESOptions =
  Js.t {.. accessKey : string, credentials : credentials, region : string, secretKey : string};

type configOptions = Js.t {.. amazonES : amazonESOptions};
