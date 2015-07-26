package com.thosedarngeeks.cpu6x09;

import org.apache.commons.cli.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class Main
{
    private static final Logger logger = LogManager.getLogger(Main.class);

    public static void main(String[] args)
    {
        logger.debug("Processing command line options");

        Options options = new Options();

        options.addOption("v", false, "Provide verbose logging");

        CommandLineParser parser = new DefaultParser();

        try
        {
            CommandLine cmd = parser.parse( options, args);
        }
        catch (ParseException e)
        {
            e.printStackTrace();
        }

        logger.debug("Ending execution");
    }
}
